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
#include "trackFilteredObject.hpp"
#include "Serial.hpp"
#include <string>
#include <iostream>
#include <termios.h>  // for tcxxxattr, ECHO, etc ..
#include <unistd.h>   // for STDIN_FILENO

#ifdef __unix
#include <cstring>
#endif




//class Process: public trackFiliteredObject,public mySerial{
class Process: public trackFiliteredObject{
public:
#ifdef __APPLE__
    
    //Process(string deviceName, int baud ,VideoCapture& video_temp):mySerial(deviceName,baud){
    //}
    Process(string deviceName, int baud ,VideoCapture& video){
        this->video = video;
    }
    
    
#elif  __unix
    Process(string deviceName, int baud ,raspicam::RaspiCam_Cv& video):mySerial(deviceName,baud){
        this->video = video;
    }
    
    
    
#endif
    void Proecess_track(void);
    void image_process(void);
    void TestGet_Y(void);
    void trackObjcet(int &x,int &y,Mat threshold,Mat &cameraFeed) override;
    void CalculateDirection();
    void CalculateDistance();
    void Control_left(int value) ;
    void Control_right(int value) ;
    void Control_middle(int value);
    void Control_Roll() ;
    void Control_Stop();
    //void Control_Back(int value);
    //void Control_Turn_back(int value) ;
    
    string byte2_4byte(int value) ;
    /*input one char without "\n"*/
    int getch(void);
private:
    /*
     * left 0~399
     * middle 400~599
     * right 600~1000
     *
     */
   
    const int Left_MIN = 0;
    const int Left_MAX = 400;
    const int middle = 1300;
    const int Right_MIN = 600;
    const int Right_MAX = 1000;
    const int Go_forward = 5100;
    const int Stop = 5000;
    //flag
    bool Flag_Roll = false;
    bool Flag_Stop = true;
    //bool Flag_Turn = false;
    int Flag_temp = 1300;
    const string S_Left = "Left_turn";
    const string S_Right = "Right_turn";
    const string S_middle = "Middle";
#ifdef __APPLE__
    VideoCapture video;
    
#elif  __unix
    raspicam::RaspiCam_Cv video;
    
#endif
    
    
};




#endif /* Process_hpp */
