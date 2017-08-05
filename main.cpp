#include <iostream>

#include "image_add.hpp"
#include "trackFilteredObject.hpp"
#include <opencv2/opencv.hpp>
#ifdef __unix
    //raspberry
    #include <raspicam/raspicam_cv.h>
    #include "image_track_pi.hpp"
    #include "Serial.hpp"
#elif __APPLE__

    #include "image_track.hpp"
#else

#endif

using namespace cv;
using namespace std;
String path_mac = "/Users/Rozen_mac/code/opencv/photo/";
String path_pi = "/home/pi/openCV/";

void StartImageTrack(){
    
}

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
        //image_track track_obj;
        trackFiliteredObject track;
        VideoCapture video(0);
        track.createTrackbars();
        track.test_hsv(video);
        //track_obj.track_start(video);
    
        video.release();
    #elif __unix
        printf("UNIX\n");
        
        //image_track_pi track_obj;
        //trackFiliteredObject track;
        //RaspiCam_Cv video;
        //if(!video.open()){cerr << "ERROR opening the camera" <<endl;return -1;}
        //track_obj.track_start(video);
        //track.test_hsv(video);
        //video.release();
    
        /*tesing in serial*/
        mySerial serial("/dev/ttyUSB0",115200);
    
        // One Byte At the time
        serial.Send(128);
        serial.Send(132);
        //close
        serial.Close();
    
        // and so on
        #elif __linux
        printf("Linux");
    #else
    
    #endif
    //image_add image_obj;
    
    
    
    cv::destroyAllWindows();
    
    return 0;
}

