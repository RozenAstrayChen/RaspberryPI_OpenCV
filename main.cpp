#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "image_add.hpp"

using namespace cv;
using namespace std;
String path = "/home/pi/openCV/";

int main(int argc, char *argv[])
{
    image_add image_obj;
    cv::Mat logo,imageROI,background;
    
    logo = cv::imread(path+"DC_Comics_logo.png");
    background = cv::imread(path+"avin.jpg");
    imageROI = image_obj.image_ROI(background, logo, 30,550, logo.cols, logo.rows);

    
    cv::addWeighted(imageROI, 1, logo, 1, 0, imageROI);
    

    //Pixel tour
    image_obj.image_visit(background, 100);
    //show
    image_obj.image_show(background);
    
    
    
    
    
    return 0;
}
