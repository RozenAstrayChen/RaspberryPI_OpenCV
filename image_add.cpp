//
//  image_add.cpp
//  OpenCV_test
//
//  Created by 陳家麒 on 2017/7/15.
//  Copyright © 2017年 陳家麒. All rights reserved.
//

#include "image_add.hpp"



Mat image_add::image_ROI(Mat background,Mat logo,int x,int y,int clos,int rows){
    Mat imageROI;
    imageROI = background(cv::Rect(x,y,clos,rows));
        
    
    return imageROI;
}

void image_add::image_show(Mat image){
    cv::namedWindow("image");
    cv::imshow("image", image);
   
    waitKey(0);
    
    return ;
}
void image_add::image_visit(Mat image,int value){
    int widthLimit = image.channels()*image.cols;
    for(int height=0;height<image.rows;height++){
        uchar* data = image.ptr<uchar>(height);
        for(int width=0;width<widthLimit;width++){
            data[width] += value;
        }
        
    }

}

