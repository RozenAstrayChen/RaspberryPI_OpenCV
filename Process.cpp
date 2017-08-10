//
//  Process.cpp
//  main
//
//  Created by 陳家麒 on 2017/8/7.
//
//

#include "Process.hpp"

using namespace std;
/*Override test_hsv function,in order to use rs232  translation*/

void Process::Proecess_track(){
    cv::namedWindow("image");
    cv::namedWindow("testing on HSV");
    cv::namedWindow("camerafeed");
    
    while(true){
        video.grab();
        video.retrieve(frame);
        if(frame.empty())return;
        
        frame.copyTo(image_frame);
        cv::cvtColor(image_frame, hsv, cv::COLOR_BGR2HSV);
        
        Multiple_inRanage(hsv, threshold, night);
        cv::inRange(hsv,Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX), threshold);
        
        
        if(useMorphOps)morphOps(threshold);
        
        if(track)trackObjcet(x, y, threshold, image_frame);
#ifdef __APPLE__
        //imshow("image", image_frame);
        imshow("testing on HSV", threshold);
        imshow("camerafeed", image_frame);
#elif __unix
	imshow("testing on HSV", threshold);
	imshow("camerafeed", image_frame);
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
                CalculateDistance();
                CalculateDirection();
                
                //draw object location on screen
                drawObject(x,y,cameraFeed);}
            
        }else putText(cameraFeed,"TOO MUCH NOISE! ADJUST FILTER",Point(0,50),1,2,Scalar(0,0,255),2);
    }

}
void Process::CalculateDirection(){
    cout << "X = " << getX() << "Y = " << getY() << endl;
    
#ifdef __APPLE__
    
    
#elif __unix
    
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

