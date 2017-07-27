#include <iostream>
#include <opencv2/opencv.hpp>
#include "image_add.hpp"


#ifdef __unix
    #include <raspicam/raspicam_cv.h>
    #include "image_track_pi.hpp"
#elif __APPLE__
    #include "image_track.hpp"
#endif

using namespace cv;
using namespace std;
String path_mac = "/Users/Rozen_mac/code/opencv/photo/";
String path_pi = "/home/pi/openCV/";



int main(int argc, char *argv[])
{
    #ifdef __WINDOWS__
        printf("Windows");
    #ifdef __WIN64
        printf("64\n");
    #elif
        printf("32\n");
    #endif
    
    #elif __APPLE__
        image_track track_obj;
        VideoCapture video(0);
        track_obj.track_start(video);
        video.release();
    #elif _unix
        printf("UNIX\n");
    
    #elif _linux
        printf("Linux");
    #else
        image_track_pi track_obj;
        RaspiCam_Cv video;
        if(!video.open())
        {
            cerr << "ERROR opening the camera" <<endl;
            return -1;
        }
        track_obj.track_start(video);
        video.release();
    #endif
    //image_add image_obj;
    
    
    
    cv::destroyAllWindows();
    
    return 0;
}

