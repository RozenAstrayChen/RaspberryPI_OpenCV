PROJECT (main)
find_package( OpenCV REQUIRED )

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")


IF (WIN32)
    MESSAGE(STATUS "Now is windows")
ELSEIF (APPLE)
    MESSAGE(STATUS "Now is Apple systens.")
    #find openCV lib mac os use
    include_directories(${OpenCV_INCLUDE_DIRS})
ELSEIF (UNIX)
    MESSAGE(STATUS "Now is UNIX-like OS's. Including aPPLE os x  and CygWin")
ENDIF ()

	

ADD_EXECUTABLE (main main.cpp)
TARGET_LINK_LIBRARIES( main ${OpenCV_LIBS} )
TARGET_LINK_LIBRARIES (main image_add)
ADD_LIBRARY (image_add image_add.cpp)