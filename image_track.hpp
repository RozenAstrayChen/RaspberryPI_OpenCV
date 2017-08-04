//
//  image_track.hpp
//  main
//
//  Created by 陳家麒 on 2017/7/24.
//
//

#ifndef image_track_hpp
#define image_track_hpp
#include <iostream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

static int hsize = 16;                   // 计算直方图所必备的内容
static float hranges[] = {0,180};        // 计算直方图所必备的内容
static const float* phranges = hranges;  // 计算直方图所必备的内容
static bool selectObject = false;
static cv::Rect selection;//save mouse select area
static int  trackObject = 0;//1 has traget,0 has'nt
static cv::Mat image;//in order to load video frame

class image_track{
public:
    image_track();
    void track_start(cv::VideoCapture video);
    
        
private:
    
    
    cv::Mat frame,hsv,hue,mask,hist,backproj;//in order to load video frame
    cv::Rect trackWindow;             // 追踪到的窗口
    
    
};

#endif /* image_track_hpp */
