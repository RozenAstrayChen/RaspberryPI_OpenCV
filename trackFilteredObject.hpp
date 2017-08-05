//
//  trackFilteredObject.hpp
//  main
//
//  Created by 陳家麒 on 2017/8/4.
//
//

#ifndef trackFilteredObject_hpp
#define trackFilteredObject_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#ifdef __unix
     #include <raspicam/raspicam_cv.h>
#elif __APPLE__

#else


#endif
#endif /* trackFilteredObject_hpp */
using namespace std;
using namespace cv;
static cv::Mat image_frame;


class trackFiliteredObject{
public:
    trackFiliteredObject();
    #ifdef __unix
        void test_hsv(raspicam::RaspiCam_Cv video);
    #elif __APPLE__
        void test_hsv(cv::VideoCapture video);
    #else
    
    #endif
    
    void createTrackbars(void);
    void morphOps(cv::Mat &thresh);
    void trackObjcet(int &x,int &y,Mat threshold,Mat &cameraFeed);
    
private:
    
    void drawObject(int x, int y,Mat &frame);
    string intToString(int number);
    void Multiple_inRanage(Mat &hsv,Mat &threshold,int arguments);
    //initial min and max HSV filter values.
    //these will be changed using trackbars
    int H_MIN = 0;
    int H_MAX = 256;
    int S_MIN = 0;
    int S_MAX = 256;
    int V_MIN = 0;
    int V_MAX = 256;
    enum hsv_arguments{default_value,morring,noon,night,night2};
    //x and y values for the location of the object
    int x=0, y=0;
    //default capture width and height
    const int FRAME_WIDTH = 640;
    const int FRAME_HEIGHT = 480;
    //max number of objects to be detected in frame
    const int MAX_NUM_OBJECTS=50;
    //minimum and maximum object area
    const int MIN_OBJECT_AREA = 20*20;
    const int MAX_OBJECT_AREA = FRAME_HEIGHT*FRAME_WIDTH/1.5;
    //flag
    bool useMorphOps = true;
    bool track = true;
    
    //names that will appear at the top of each window
    const string windowName = "Original Image";
    const string windowName1 = "HSV Image";
    const string windowName2 = "Thresholded Image";
    const string windowName3 = "After Morphological Operations";
    const string trackbarWindowName = "Trackbars";
    cv::Mat frame,hsv,threshold,cameraFeed;
};
