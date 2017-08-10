//
//  Control.hpp
//  main
//
//  Created by 陳家麒 on 2017/8/6.
//
//

#ifndef Control_hpp
#define Control_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <termios.h>  // for tcxxxattr, ECHO, etc ..
#include <unistd.h>   // for STDIN_FILENO
#include "Serial.hpp"
#ifdef __unix
#include <cstring>
#endif

class Control :public mySerial{
public:
    Control(string deviceName, int baud):mySerial(deviceName,baud){
        
    }
    void test_direction();
    void Control_left(int value);
    void Control_right(int value);
    void Control_ahead(int value);
    void Control_Back(int value);
    void Control_Turn_back(int value);
    string byte2_4byte(int value);
    /*input one char without "\n"*/
    int getch(void);
private:
    double left = 500;
    double right = 2500;
    double mid = 1500; 
    
    
};

#endif /* Control_hpp */
