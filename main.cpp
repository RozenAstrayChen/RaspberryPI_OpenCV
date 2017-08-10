#include <iostream>

#include "image_add.hpp"
#include <opencv2/opencv.hpp>
#include <thread>
#include "Process.hpp"
//#include "trackFiliteredObject.hpp"

#ifdef __unix
    //raspberry
    #include <raspicam/raspicam_cv.h>
    #include "image_track_pi.hpp"
    using namespace raspicam;


#elif __APPLE__

    #include "image_track.hpp"

#else

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
    VideoCapture video(0);
    Process process("/dev/ttyUSB0",115200,video);
    process.Proecess_track();
    video.release();
    #elif __unix
    printf("UNIX\n");
    RaspiCam_Cv video ;
    //Process process("/dev/ttyUSB0",115200,video);
    if(!video.open()){cerr << "Error opening the camera"<<endl;return -1;}
    
    //process.Proecess_track();

    trackFiliteredObject track;
    track.createTrackbars();
    track.test_hsv(video);
    video.release();
    
    //process.Send("fuck you");
    
    
        // and so on
    #elif __linux
        printf("Linux");
    #else
    
    #endif
    //image_add image_obj;
    
    
    
    cv::destroyAllWindows();
    
    return 0;
}

