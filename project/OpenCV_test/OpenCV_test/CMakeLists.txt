PROJECT (main)
find_package( OpenCV REQUIRED )
ADD_EXECUTABLE (main main.cpp)
TARGET_LINK_LIBRARIES( main ${OpenCV_LIBS} )

TARGET_LINK_LIBRARIES (main image_add)
ADD_LIBRARY (image_add image_add.cpp)