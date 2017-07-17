PROJECT (main)
find_package( OpenCV REQUIRED )

#find openCV lib
include_directories(${OpenCV_INCLUDE_DIRS})

ADD_EXECUTABLE (main main.cpp)
TARGET_LINK_LIBRARIES( main ${OpenCV_LIBS} )

TARGET_LINK_LIBRARIES (main image_add)
ADD_LIBRARY (image_add image_add.cpp)