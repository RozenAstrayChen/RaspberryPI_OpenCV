//
//  Process.cpp
//  main
//
//  Created by 陳家麒 on 2017/8/7.
//
//

#include "Process.hpp"

using namespace std;
int Process::getch(){
    int ch;
    struct termios oldt, newt;
    
    tcgetattr(STDIN_FILENO, &oldt);
    memcpy(&newt, &oldt, sizeof(newt));
    newt.c_lflag &= ~( ECHO | ICANON | ECHOE | ECHOK |
                      ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    return ch;
}
void Process::Control_left(int value){
    if(Flag_temp > value-50 && Flag_temp < value+50)
        return;
    string s = byte2_4byte(value);
    cout << "↖\t" << s << endl;
    Flag_temp = value;
    
#ifdef __unix
    Send(s);
#endif
}
void Process::Control_right(int value){
    if(Flag_temp > value-50 && Flag_temp < value+50)
        return;
    string s = byte2_4byte(value);
    cout << "↗\t" << s << endl;
    Flag_temp = value;
    
#ifdef __unix
    Send(s);
#endif
}
void Process::Control_middle(int value){
    if(Flag_temp > value-50 && Flag_temp < value+50)
        return;
    string s = byte2_4byte(middle);
    cout << "↑\t" << s << endl;
    Flag_temp = value;
    
#ifdef __unix
    Send(s);
#endif
}

void Process::Control_Roll(){
    
    string s = byte2_4byte(Go_forward);
    //left
    if(getX() >Left_MIN && getX() < Left_MAX){
        cout << "↖\tRoll!!\t" << s << endl;
    }// middle
    else if(getX() > Left_MAX &&  getX() < Right_MIN){
        cout << "↑\tRoll!!\t" << s << endl;
    }//right turn
    else if(getX() > Right_MIN && getX() < Right_MAX){
        cout << "↗\tRoll!!\t" << s << endl;
    }

    
    
#ifdef __unix
        Send(s);
#endif
    
}
void Process::Control_Stop(){
    
    string s = byte2_4byte(Stop);
    cout << "Stop\t" << s << endl;
    
#ifdef __unix
        Send(s);
#endif
    
}
string Process::byte2_4byte(int value){
    int value_int = (int)value;
    char* temp = nullptr;
    
    string s = to_string(value_int);
    if(s.size()<4){
        sprintf(temp, "%04d",value_int);
        s.assign(temp);
        
    }else if(s.size()>4){
        return "funcking_error";
    }else{
        
    }
    return  s;
}

/*Override test_hsv function,in order to use rs232  translation*/

void Process::Proecess_track(){
    cv::namedWindow("testing on HSV");
    //cv::namedWindow("camerafeed");
    
    while(true){
        video.grab();
        video.retrieve(frame);
        if(frame.empty())return;
        
        frame.copyTo(image_frame);
        cv::cvtColor(image_frame, hsv, cv::COLOR_BGR2HSV);
#ifdef __APPLE__
        Multiple_inRanage(hsv, threshold, night);
#elif __unix
        Multiple_inRanage(hsv, threshold, morring_pi );
#endif
        cv::inRange(hsv,Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX), threshold);
        
        
        if(useMorphOps)morphOps(threshold);
        
        if(track)trackObjcet(x, y, threshold, image_frame);
#ifdef __APPLE__
       
        imshow("testing on HSV", threshold);
        imshow("camerafeed", image_frame);
#elif __unix
        imshow("testing on HSV", threshold);
        //imshow("camerafeed", image_frame);
#endif
        
        char c = (char)cv::waitKey(1000/15.0);
        if( c == 27 )
            break;
    }

}


void Process::trackObjcet(int &x,int &y,Mat threshold,Mat &cameraFeed) {
    Mat temp;
    threshold.copyTo(temp);
    //these two vectors need for output findcontours
    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;
    //find contours of filtered image using Opencv find Contours function
    findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE);
    //use moments method to find our filtered object
    double refArea = 0;
    bool objectFound = false;
    if (hierarchy.size() > 0) {
        int numObjects = hierarchy.size();
        //if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
        if(numObjects<MAX_NUM_OBJECTS){
            for (int index = 0; index >= 0; index = hierarchy[index][0]) {
                
                Moments moment = moments((cv::Mat)contours[index]);
                double area = moment.m00;
                /*judgement distance*/
                writeRange(area);
                //if the area is less than 20 px by 20px then it is probably just noise
                //if the area is the same as the 3/2 of the image size, probably just a bad filter
                //we only want the object with the largest area so we safe a reference area each
                //iteration and compare it to the area in the next iteration.
                if(area>MIN_OBJECT_AREA && area<MAX_OBJECT_AREA && area>refArea){
                    x = moment.m10/area;
                    y = moment.m01/area;
                    
                    objectFound = true;
                    
                    refArea = area;
                }else if(area> MAX_OBJECT_AREA){
                   
                    putText(cameraFeed,"Tracking STOP!",Point(0,50),2,1,Scalar(0,0,255),2);
                    

                    objectFound = false;
                   
                }else {
                    objectFound = false;
                }
                
            }
            //let user know you found an object
            if(objectFound ==true){
                
                putText(cameraFeed,"Tracking Object",Point(0,50),2,1,Scalar(0,255,0),2);
                
                //write x,y in object
                writeXY(x, y);
                //stop = 1;roll = 0;
              
                CalculateDistance();
                CalculateDirection_new();
                
                //draw object location on screen
                drawObject(x,y,cameraFeed);
            }else{
                //stop = 0;roll = 1;
                if(Flag_Stop == 0 && Flag_Roll== 1){
                    Flag_Roll = false;
                    Flag_Stop = true;
                    Control_Stop();
                }
            }
            
        }else putText(cameraFeed,"TOO MUCH NOISE! ADJUST FILTER",Point(0,50),1,2,Scalar(0,0,255),2);
    }

}
/*
 * left 0~399
 * middle 400~599
 * right 600~1000
 *
 */
void Process::CalculateDirection(){
    //cout << "X = " << getX() << "Y = " << getY() << endl;
    int value = 1300;
    //left turn
    if(getX() >Left_MIN && getX() < Left_MAX){
        value = getX()/2;
        value = middle - value;
        //left,if temp and value less middle that is servo already  turn left
        if(!(value < middle && Flag_temp <middle)){
            cout << S_Left << endl;
            Control_left(value);
        }
    }// middle
    else if(getX() > Left_MAX &&  getX() < Right_MIN){
        value = middle;
        if(!(value == middle && Flag_temp == middle)){
            cout << S_middle << endl;
            Control_middle(value);
        }
    }//right turn
    else if(getX() > Right_MIN && getX() < Right_MAX){
        value = (getX() -800)/2;
        value = middle + value;
        //right,if temp and value more middle that is servo already  turn right
        if(!(value > middle && Flag_temp >middle)){
            cout << S_Right << endl;
            Control_right(value);
        }
    }

}
void Process::CalculateDirection_new(){
    int value = 1300;
    if(getX() > Left_MIN && getX() < Left_MAX){
        value = getX()/1.7;
        value = (middle - 350) + value;
        Control_left(value);
    }if(getX() > Left_MAX &&  getX() < Right_MIN){
        value = middle;
        Control_middle(value);
        
    }if(getX() > Right_MIN && getX() < Right_MAX){
        value = (getX() -Left_MAX)/1.7;
        value = middle  + value;
        Control_right(value);
        
    }
}
void Process::CalculateDistance(){
    //cout << "Range = " << getRange() << endl;
    //stop = 1;roll = 0;
    if(Flag_Stop == 1 && Flag_Roll== 0){
        Flag_Roll = true;
        Flag_Stop = false;
        Control_Roll();
    }


#ifdef __APPLE__
    
    
#elif __unix
    
#endif
}

void Process::image_process(){
    test_hsv(video);
    
       
    
}
void Process::TestGet_Y(){
    while(1){
        cout << getY() << endl;
    }
}

