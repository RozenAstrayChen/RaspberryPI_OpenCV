# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.Serial.Debug:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libSerial.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libSerial.a


PostBuild.image_add.Debug:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libimage_add.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libimage_add.a


PostBuild.image_track.Debug:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libimage_track.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libimage_track.a


PostBuild.main.Debug:
PostBuild.image_add.Debug: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/main
PostBuild.image_track.Debug: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/main
PostBuild.trackFilteredObject.Debug: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/main
PostBuild.Serial.Debug: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/main
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/main:\
	/usr/local/lib/libopencv_videostab.2.4.13.dylib\
	/usr/local/lib/libopencv_ts.a\
	/usr/local/lib/libopencv_superres.2.4.13.dylib\
	/usr/local/lib/libopencv_stitching.2.4.13.dylib\
	/usr/local/lib/libopencv_contrib.2.4.13.dylib\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libimage_add.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libimage_track.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libtrackFilteredObject.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libSerial.a\
	/usr/local/lib/libopencv_nonfree.2.4.13.dylib\
	/usr/local/lib/libopencv_ocl.2.4.13.dylib\
	/usr/local/lib/libopencv_gpu.2.4.13.dylib\
	/usr/local/lib/libopencv_photo.2.4.13.dylib\
	/usr/local/lib/libopencv_objdetect.2.4.13.dylib\
	/usr/local/lib/libopencv_legacy.2.4.13.dylib\
	/usr/local/lib/libopencv_video.2.4.13.dylib\
	/usr/local/lib/libopencv_ml.2.4.13.dylib\
	/usr/local/lib/libopencv_calib3d.2.4.13.dylib\
	/usr/local/lib/libopencv_features2d.2.4.13.dylib\
	/usr/local/lib/libopencv_highgui.2.4.13.dylib\
	/usr/local/lib/libopencv_imgproc.2.4.13.dylib\
	/usr/local/lib/libopencv_flann.2.4.13.dylib\
	/usr/local/lib/libopencv_core.2.4.13.dylib
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/main


PostBuild.trackFilteredObject.Debug:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libtrackFilteredObject.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libtrackFilteredObject.a


PostBuild.Serial.Release:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libSerial.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libSerial.a


PostBuild.image_add.Release:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libimage_add.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libimage_add.a


PostBuild.image_track.Release:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libimage_track.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libimage_track.a


PostBuild.main.Release:
PostBuild.image_add.Release: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/main
PostBuild.image_track.Release: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/main
PostBuild.trackFilteredObject.Release: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/main
PostBuild.Serial.Release: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/main
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/main:\
	/usr/local/lib/libopencv_videostab.2.4.13.dylib\
	/usr/local/lib/libopencv_ts.a\
	/usr/local/lib/libopencv_superres.2.4.13.dylib\
	/usr/local/lib/libopencv_stitching.2.4.13.dylib\
	/usr/local/lib/libopencv_contrib.2.4.13.dylib\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libimage_add.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libimage_track.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libtrackFilteredObject.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libSerial.a\
	/usr/local/lib/libopencv_nonfree.2.4.13.dylib\
	/usr/local/lib/libopencv_ocl.2.4.13.dylib\
	/usr/local/lib/libopencv_gpu.2.4.13.dylib\
	/usr/local/lib/libopencv_photo.2.4.13.dylib\
	/usr/local/lib/libopencv_objdetect.2.4.13.dylib\
	/usr/local/lib/libopencv_legacy.2.4.13.dylib\
	/usr/local/lib/libopencv_video.2.4.13.dylib\
	/usr/local/lib/libopencv_ml.2.4.13.dylib\
	/usr/local/lib/libopencv_calib3d.2.4.13.dylib\
	/usr/local/lib/libopencv_features2d.2.4.13.dylib\
	/usr/local/lib/libopencv_highgui.2.4.13.dylib\
	/usr/local/lib/libopencv_imgproc.2.4.13.dylib\
	/usr/local/lib/libopencv_flann.2.4.13.dylib\
	/usr/local/lib/libopencv_core.2.4.13.dylib
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/main


PostBuild.trackFilteredObject.Release:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libtrackFilteredObject.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libtrackFilteredObject.a


PostBuild.Serial.MinSizeRel:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libSerial.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libSerial.a


PostBuild.image_add.MinSizeRel:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libimage_add.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libimage_add.a


PostBuild.image_track.MinSizeRel:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libimage_track.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libimage_track.a


PostBuild.main.MinSizeRel:
PostBuild.image_add.MinSizeRel: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/main
PostBuild.image_track.MinSizeRel: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/main
PostBuild.trackFilteredObject.MinSizeRel: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/main
PostBuild.Serial.MinSizeRel: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/main
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/main:\
	/usr/local/lib/libopencv_videostab.2.4.13.dylib\
	/usr/local/lib/libopencv_ts.a\
	/usr/local/lib/libopencv_superres.2.4.13.dylib\
	/usr/local/lib/libopencv_stitching.2.4.13.dylib\
	/usr/local/lib/libopencv_contrib.2.4.13.dylib\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libimage_add.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libimage_track.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libtrackFilteredObject.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libSerial.a\
	/usr/local/lib/libopencv_nonfree.2.4.13.dylib\
	/usr/local/lib/libopencv_ocl.2.4.13.dylib\
	/usr/local/lib/libopencv_gpu.2.4.13.dylib\
	/usr/local/lib/libopencv_photo.2.4.13.dylib\
	/usr/local/lib/libopencv_objdetect.2.4.13.dylib\
	/usr/local/lib/libopencv_legacy.2.4.13.dylib\
	/usr/local/lib/libopencv_video.2.4.13.dylib\
	/usr/local/lib/libopencv_ml.2.4.13.dylib\
	/usr/local/lib/libopencv_calib3d.2.4.13.dylib\
	/usr/local/lib/libopencv_features2d.2.4.13.dylib\
	/usr/local/lib/libopencv_highgui.2.4.13.dylib\
	/usr/local/lib/libopencv_imgproc.2.4.13.dylib\
	/usr/local/lib/libopencv_flann.2.4.13.dylib\
	/usr/local/lib/libopencv_core.2.4.13.dylib
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/main


PostBuild.trackFilteredObject.MinSizeRel:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libtrackFilteredObject.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libtrackFilteredObject.a


PostBuild.Serial.RelWithDebInfo:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libSerial.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libSerial.a


PostBuild.image_add.RelWithDebInfo:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libimage_add.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libimage_add.a


PostBuild.image_track.RelWithDebInfo:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libimage_track.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libimage_track.a


PostBuild.main.RelWithDebInfo:
PostBuild.image_add.RelWithDebInfo: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/main
PostBuild.image_track.RelWithDebInfo: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/main
PostBuild.trackFilteredObject.RelWithDebInfo: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/main
PostBuild.Serial.RelWithDebInfo: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/main
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/main:\
	/usr/local/lib/libopencv_videostab.2.4.13.dylib\
	/usr/local/lib/libopencv_ts.a\
	/usr/local/lib/libopencv_superres.2.4.13.dylib\
	/usr/local/lib/libopencv_stitching.2.4.13.dylib\
	/usr/local/lib/libopencv_contrib.2.4.13.dylib\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libimage_add.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libimage_track.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libtrackFilteredObject.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libSerial.a\
	/usr/local/lib/libopencv_nonfree.2.4.13.dylib\
	/usr/local/lib/libopencv_ocl.2.4.13.dylib\
	/usr/local/lib/libopencv_gpu.2.4.13.dylib\
	/usr/local/lib/libopencv_photo.2.4.13.dylib\
	/usr/local/lib/libopencv_objdetect.2.4.13.dylib\
	/usr/local/lib/libopencv_legacy.2.4.13.dylib\
	/usr/local/lib/libopencv_video.2.4.13.dylib\
	/usr/local/lib/libopencv_ml.2.4.13.dylib\
	/usr/local/lib/libopencv_calib3d.2.4.13.dylib\
	/usr/local/lib/libopencv_features2d.2.4.13.dylib\
	/usr/local/lib/libopencv_highgui.2.4.13.dylib\
	/usr/local/lib/libopencv_imgproc.2.4.13.dylib\
	/usr/local/lib/libopencv_flann.2.4.13.dylib\
	/usr/local/lib/libopencv_core.2.4.13.dylib
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/main


PostBuild.trackFilteredObject.RelWithDebInfo:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libtrackFilteredObject.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libtrackFilteredObject.a




# For each target create a dummy ruleso the target does not have to exist
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libSerial.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libimage_add.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libimage_track.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libtrackFilteredObject.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libSerial.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libimage_add.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libimage_track.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libtrackFilteredObject.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libSerial.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libimage_add.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libimage_track.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libtrackFilteredObject.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libSerial.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libimage_add.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libimage_track.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libtrackFilteredObject.a:
/usr/local/lib/libopencv_calib3d.2.4.13.dylib:
/usr/local/lib/libopencv_contrib.2.4.13.dylib:
/usr/local/lib/libopencv_core.2.4.13.dylib:
/usr/local/lib/libopencv_features2d.2.4.13.dylib:
/usr/local/lib/libopencv_flann.2.4.13.dylib:
/usr/local/lib/libopencv_gpu.2.4.13.dylib:
/usr/local/lib/libopencv_highgui.2.4.13.dylib:
/usr/local/lib/libopencv_imgproc.2.4.13.dylib:
/usr/local/lib/libopencv_legacy.2.4.13.dylib:
/usr/local/lib/libopencv_ml.2.4.13.dylib:
/usr/local/lib/libopencv_nonfree.2.4.13.dylib:
/usr/local/lib/libopencv_objdetect.2.4.13.dylib:
/usr/local/lib/libopencv_ocl.2.4.13.dylib:
/usr/local/lib/libopencv_photo.2.4.13.dylib:
/usr/local/lib/libopencv_stitching.2.4.13.dylib:
/usr/local/lib/libopencv_superres.2.4.13.dylib:
/usr/local/lib/libopencv_ts.a:
/usr/local/lib/libopencv_video.2.4.13.dylib:
/usr/local/lib/libopencv_videostab.2.4.13.dylib:
