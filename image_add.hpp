//
//  image_add.hpp
//  OpenCV_test
//
//  Created by 陳家麒 on 2017/7/15.
//  Copyright © 2017年 陳家麒. All rights reserved.
//

#ifndef image_add_hpp
#define image_add_hpp

#include <stdio.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"



using namespace cv;
using namespace std;
//String path = "/Users/Rozen_mac/code/opencv/photo/";

class image_add{
public:
    cv::Mat image_ROI(cv::Mat background,cv::Mat logo,int x,int y,int clos,int rows);
    void image_show(Mat image);
    void image_visit(Mat image,int value);
};

#endif /* image_add_hpp */
