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
    
    //Process(string deviceName, int baud ,VideoCapture& video_temp):Control(deviceName,baud){
    //    this->video = video;
    //}
    Process(string deviceName, int baud ,VideoCapture& video){
            this->video = video;
    }
    
    
    
    
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
private:
#ifdef __APPLE__
    VideoCapture video;
    
#elif  __unix
    raspicam::RaspiCam_Cv video;
    
#endif
    
    
};




#endif /* Process_hpp */
