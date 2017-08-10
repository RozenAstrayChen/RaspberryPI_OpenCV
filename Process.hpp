//
//  Process.hpp
//  main
//
//  Created by 陳家麒 on 2017/8/7.
//
//

#ifndef Process_hpp
#define Process_hpp

#include <stdio.h>
#include <thread>
#include <future>
#include "Control.hpp"
#include "trackFilteredObject.hpp"


//class Process:public trackFiliteredObject,public Control;

class Process: public trackFiliteredObject,public Control{
public:
#ifdef __APPLE__
    
    Process(string deviceName, int baud ,VideoCapture& video_temp):Control(deviceName,baud){
        this->video = video;
    }
    //Process(string deviceName, int baud ,VideoCapture& video){
       // this->video = video;
    //}
    
    
#elif  __unix
    Process(string deviceName, int baud ,raspicam::RaspiCam_Cv& video):Control(deviceName,baud){
        this->video = video;
    }
    
    
    
#endif
    void Proecess_track(void);
    void image_process(void);
    void TestGet_Y(void);
    void trackObjcet(int &x,int &y,Mat threshold,Mat &cameraFeed) override;
    void CalculateDirection();
    void CalculateDistance();
    void Control_left(int value) override;
    void Control_right(int value) override;
    void Control_ahead(int value) override;
    void Control_Back(int value) override;
    void Control_Turn_back(int value) override;
private:
    /*
     * left 0~399
     * middle 400~599
     * right 600~1000
     *
     */
    int Left_MIN = 0;
    int Left_MAX = 400;
    int middle = 1300;
    int Right_MIN = 600;
    int Right_MAX = 1000;
    const string S_Left = "Left_turn";
    const string S_Right = "Right_turn";
    const string S_middle = "go foward";
#ifdef __APPLE__
    VideoCapture video;
    
#elif  __unix
    raspicam::RaspiCam_Cv video;
    
#endif
    
    
};




#endif /* Process_hpp */
