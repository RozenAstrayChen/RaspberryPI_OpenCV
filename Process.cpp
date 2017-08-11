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
    
    string s = byte2_4byte(value);
    cout << s << endl;
    Send(s);
}
void Process::Control_right(int value){
    
    string s = byte2_4byte(value);
    Send(s);
}
void Process::Control_ahead(int value){
    
    string s = byte2_4byte(value);
    Send(s);
}
void Process::Control_Back(int value){
    

    string s = byte2_4byte(value);
    cout << s << endl;
    Send(s);
}
void Process::Control_Turn_back(int value){

    string s = byte2_4byte(value);
    cout << s << endl;
    Send(s);
}
void Process::Control_Stop(int value){
   string s = byte2_4byte(value);
    cout << s << endl;
    Send(s);
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
    cout << s << endl;
    return  s;
}

/*Override test_hsv function,in order to use rs232  translation*/

void Process::Proecess_track(){
    cv::namedWindow("testing on HSV");
    cv::namedWindow("camerafeed");
    
    while(true){
        video.grab();
        video.retrieve(frame);
        if(frame.empty())return;
        
        frame.copyTo(image_frame);
        cv::cvtColor(image_frame, hsv, cv::COLOR_BGR2HSV);
#ifdef __APPLE__
        Multiple_inRanage(hsv, threshold, morring);
#elif __unix
        Multiple_inRanage(hsv, threshold, night );
#endif
        cv::inRange(hsv,Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX), threshold);
        
        
        if(useMorphOps)morphOps(threshold);
        
        if(track)trackObjcet(x, y, threshold, image_frame);
#ifdef __APPLE__
       
        imshow("testing on HSV", threshold);
        imshow("camerafeed", image_frame);
#elif __unix
        //imshow("testing on HSV", threshold);
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
                    
                    /*use rs232 sned data*/
#ifdef __APPLE__
                    cout << "Tracking STOP!" << endl;
#elif __unix
                    
#endif
                    
                    objectFound = false;
                }else objectFound = false;
                
                
            }
            //let user know you found an object
            if(objectFound ==true){
                putText(cameraFeed,"Tracking Object",Point(0,50),2,1,Scalar(0,255,0),2);
                //write x,y in object
                writeXY(x, y);
                //CalculateDistance();
                CalculateDirection();
                
                //draw object location on screen
                drawObject(x,y,cameraFeed);}
            
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
    int value = middle;
    if(getX() >Left_MIN && getX() < Left_MAX){
        value = getX()/2;
        value = middle - value;
    }else if(getX() > Left_MAX &&  getX() < Right_MIN){
        value = middle;
    }else if(getX() > Right_MIN && getX() < Right_MAX){
        value = getX()/2;
        value = middle + value;
    }
#ifdef __APPLE__
    if(value < middle){
        cout << S_Left << endl;
    }else if(value > middle){
         cout << S_Right << endl;
    }else{
         cout << S_middle << endl;
    }
    
#elif __unix
    if(value < middle){
        cout << S_Left << endl;
        Control_left(value);
    }else if(value > middle){
        cout << S_Right << endl;
        Control_right(value);
    }else{
        cout << S_middle << endl;
        Control_ahead(value);
    }
#endif
}
void Process::CalculateDistance(){
    cout << "Range = " << getRange() << endl;
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

