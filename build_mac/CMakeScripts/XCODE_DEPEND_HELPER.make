# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.Control.Debug:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libControl.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libControl.a


PostBuild.Process.Debug:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libProcess.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libProcess.a


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
PostBuild.Control.Debug: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/main
PostBuild.Process.Debug: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/main
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/main:\
	/opt/local/lib/libopencv_shape.3.2.0.dylib\
	/opt/local/lib/libopencv_stitching.3.2.0.dylib\
	/opt/local/lib/libopencv_superres.3.2.0.dylib\
	/opt/local/lib/libopencv_videostab.3.2.0.dylib\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libimage_add.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libimage_track.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libtrackFilteredObject.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libSerial.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libControl.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libProcess.a\
	/opt/local/lib/libopencv_objdetect.3.2.0.dylib\
	/opt/local/lib/libopencv_calib3d.3.2.0.dylib\
	/opt/local/lib/libopencv_features2d.3.2.0.dylib\
	/opt/local/lib/libopencv_flann.3.2.0.dylib\
	/opt/local/lib/libopencv_highgui.3.2.0.dylib\
	/opt/local/lib/libopencv_ml.3.2.0.dylib\
	/opt/local/lib/libopencv_photo.3.2.0.dylib\
	/opt/local/lib/libopencv_video.3.2.0.dylib\
	/opt/local/lib/libopencv_videoio.3.2.0.dylib\
	/opt/local/lib/libopencv_imgcodecs.3.2.0.dylib\
	/opt/local/lib/libopencv_imgproc.3.2.0.dylib\
	/opt/local/lib/libopencv_core.3.2.0.dylib
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/main


PostBuild.trackFilteredObject.Debug:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libtrackFilteredObject.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libtrackFilteredObject.a


PostBuild.Control.Release:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libControl.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libControl.a


PostBuild.Process.Release:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libProcess.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libProcess.a


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
PostBuild.Control.Release: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/main
PostBuild.Process.Release: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/main
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/main:\
	/opt/local/lib/libopencv_shape.3.2.0.dylib\
	/opt/local/lib/libopencv_stitching.3.2.0.dylib\
	/opt/local/lib/libopencv_superres.3.2.0.dylib\
	/opt/local/lib/libopencv_videostab.3.2.0.dylib\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libimage_add.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libimage_track.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libtrackFilteredObject.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libSerial.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libControl.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libProcess.a\
	/opt/local/lib/libopencv_objdetect.3.2.0.dylib\
	/opt/local/lib/libopencv_calib3d.3.2.0.dylib\
	/opt/local/lib/libopencv_features2d.3.2.0.dylib\
	/opt/local/lib/libopencv_flann.3.2.0.dylib\
	/opt/local/lib/libopencv_highgui.3.2.0.dylib\
	/opt/local/lib/libopencv_ml.3.2.0.dylib\
	/opt/local/lib/libopencv_photo.3.2.0.dylib\
	/opt/local/lib/libopencv_video.3.2.0.dylib\
	/opt/local/lib/libopencv_videoio.3.2.0.dylib\
	/opt/local/lib/libopencv_imgcodecs.3.2.0.dylib\
	/opt/local/lib/libopencv_imgproc.3.2.0.dylib\
	/opt/local/lib/libopencv_core.3.2.0.dylib
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/main


PostBuild.trackFilteredObject.Release:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libtrackFilteredObject.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libtrackFilteredObject.a


PostBuild.Control.MinSizeRel:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libControl.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libControl.a


PostBuild.Process.MinSizeRel:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libProcess.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libProcess.a


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
PostBuild.Control.MinSizeRel: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/main
PostBuild.Process.MinSizeRel: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/main
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/main:\
	/opt/local/lib/libopencv_shape.3.2.0.dylib\
	/opt/local/lib/libopencv_stitching.3.2.0.dylib\
	/opt/local/lib/libopencv_superres.3.2.0.dylib\
	/opt/local/lib/libopencv_videostab.3.2.0.dylib\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libimage_add.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libimage_track.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libtrackFilteredObject.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libSerial.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libControl.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libProcess.a\
	/opt/local/lib/libopencv_objdetect.3.2.0.dylib\
	/opt/local/lib/libopencv_calib3d.3.2.0.dylib\
	/opt/local/lib/libopencv_features2d.3.2.0.dylib\
	/opt/local/lib/libopencv_flann.3.2.0.dylib\
	/opt/local/lib/libopencv_highgui.3.2.0.dylib\
	/opt/local/lib/libopencv_ml.3.2.0.dylib\
	/opt/local/lib/libopencv_photo.3.2.0.dylib\
	/opt/local/lib/libopencv_video.3.2.0.dylib\
	/opt/local/lib/libopencv_videoio.3.2.0.dylib\
	/opt/local/lib/libopencv_imgcodecs.3.2.0.dylib\
	/opt/local/lib/libopencv_imgproc.3.2.0.dylib\
	/opt/local/lib/libopencv_core.3.2.0.dylib
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/main


PostBuild.trackFilteredObject.MinSizeRel:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libtrackFilteredObject.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libtrackFilteredObject.a


PostBuild.Control.RelWithDebInfo:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libControl.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libControl.a


PostBuild.Process.RelWithDebInfo:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libProcess.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libProcess.a


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
PostBuild.Control.RelWithDebInfo: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/main
PostBuild.Process.RelWithDebInfo: /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/main
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/main:\
	/opt/local/lib/libopencv_shape.3.2.0.dylib\
	/opt/local/lib/libopencv_stitching.3.2.0.dylib\
	/opt/local/lib/libopencv_superres.3.2.0.dylib\
	/opt/local/lib/libopencv_videostab.3.2.0.dylib\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libimage_add.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libimage_track.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libtrackFilteredObject.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libSerial.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libControl.a\
	/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libProcess.a\
	/opt/local/lib/libopencv_objdetect.3.2.0.dylib\
	/opt/local/lib/libopencv_calib3d.3.2.0.dylib\
	/opt/local/lib/libopencv_features2d.3.2.0.dylib\
	/opt/local/lib/libopencv_flann.3.2.0.dylib\
	/opt/local/lib/libopencv_highgui.3.2.0.dylib\
	/opt/local/lib/libopencv_ml.3.2.0.dylib\
	/opt/local/lib/libopencv_photo.3.2.0.dylib\
	/opt/local/lib/libopencv_video.3.2.0.dylib\
	/opt/local/lib/libopencv_videoio.3.2.0.dylib\
	/opt/local/lib/libopencv_imgcodecs.3.2.0.dylib\
	/opt/local/lib/libopencv_imgproc.3.2.0.dylib\
	/opt/local/lib/libopencv_core.3.2.0.dylib
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/main


PostBuild.trackFilteredObject.RelWithDebInfo:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libtrackFilteredObject.a:
	/bin/rm -f /Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libtrackFilteredObject.a




# For each target create a dummy ruleso the target does not have to exist
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libControl.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libProcess.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libSerial.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libimage_add.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libimage_track.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Debug/libtrackFilteredObject.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libControl.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libProcess.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libSerial.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libimage_add.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libimage_track.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/MinSizeRel/libtrackFilteredObject.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libControl.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libProcess.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libSerial.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libimage_add.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libimage_track.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/RelWithDebInfo/libtrackFilteredObject.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libControl.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libProcess.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libSerial.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libimage_add.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libimage_track.a:
/Users/Rozen_mac/code/opencv/project/cmake_test/build_mac/Release/libtrackFilteredObject.a:
/opt/local/lib/libopencv_calib3d.3.2.0.dylib:
/opt/local/lib/libopencv_core.3.2.0.dylib:
/opt/local/lib/libopencv_features2d.3.2.0.dylib:
/opt/local/lib/libopencv_flann.3.2.0.dylib:
/opt/local/lib/libopencv_highgui.3.2.0.dylib:
/opt/local/lib/libopencv_imgcodecs.3.2.0.dylib:
/opt/local/lib/libopencv_imgproc.3.2.0.dylib:
/opt/local/lib/libopencv_ml.3.2.0.dylib:
/opt/local/lib/libopencv_objdetect.3.2.0.dylib:
/opt/local/lib/libopencv_photo.3.2.0.dylib:
/opt/local/lib/libopencv_shape.3.2.0.dylib:
/opt/local/lib/libopencv_stitching.3.2.0.dylib:
/opt/local/lib/libopencv_superres.3.2.0.dylib:
/opt/local/lib/libopencv_video.3.2.0.dylib:
/opt/local/lib/libopencv_videoio.3.2.0.dylib:
/opt/local/lib/libopencv_videostab.3.2.0.dylib:
