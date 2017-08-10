PROJECT (main)
find_package( OpenCV REQUIRED )

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")


IF (WIN32)
    MESSAGE(STATUS "Now is windows")
ELSEIF (APPLE)
    MESSAGE(STATUS "Now is Apple systens.")
    #find openCV lib mac os use
    include_directories( ${OpenCV_INCLUDE_DIRS} )
    
ELSEIF (UNIX)
# use raspberry pi
    MESSAGE(STATUS "Now is UNIX-like OS's. Including aPPLE os x  and CygWin")
    #set path by raspicam
    set(raspicam_DIR "/usr/local/lib/cmake")
    find_package(raspicam REQUIRED)
ENDIF ()

# C++ compile flags
# -std=c++11 -> for c++ standarts
# -Wall for WARNING
# -pedantic -> for warning between c and c++
# -pthread for portability
# -g -O0 -fprofile-arcs -ftest-coverage for code coverage
if(NOT CMAKE_VERSION VERSION_LESS 3.1)
    set(CMAKE_CXX_STANDARD 11)
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")
	

ADD_EXECUTABLE (main main.cpp)
TARGET_LINK_LIBRARIES( main ${OpenCV_LIBS} )
TARGET_LINK_LIBRARIES (main image_add)
TARGET_LINK_LIBRARIES (main image_track)
TARGET_LINK_LIBRARIES (main trackFilteredObject)
TARGET_LINK_LIBRARIES (main Serial)
TARGET_LINK_LIBRARIES (main Control)
TARGET_LINK_LIBRARIES (main Process)

#raspberry
IF(OpenCV_FOUND AND raspicam_CV_FOUND)
    MESSAGE(STATUS "raspberry use raspicam to control camera")
    TARGET_LINK_LIBRARIES (main image_track_pi)
    TARGET_LINK_LIBRARIES(main ${raspicam_CV_LIBS})

ELSE()
    MESSAGE(STATUS "not include raspicam")
ENDIF()

#add other file to link
ADD_LIBRARY (image_add image_add.cpp)
ADD_LIBRARY (image_track image_track.cpp)
ADD_LIBRARY (trackFilteredObject trackFilteredObject.cpp)
ADD_LIBRARY (Serial Serial.cpp)
ADD_LIBRARY (Control Control.cpp)
ADD_LIBRARY (Process Process.cpp)

#raspberry
IF(OpenCV_FOUND AND raspicam_CV_FOUND)
    MESSAGE(STATUS "raspberry use raspicam to control camera")
    ADD_LIBRARY (image_track_pi image_track_pi.cpp)
    

ELSE()
    MESSAGE(STATUS "not include raspicam")
ENDIF()

