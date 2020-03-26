#--------------------------------------------------------------#
#	   Makefile for TrackerSystem creation simplification      #
#--------------------------------------------------------------#

COMPILER = g++

FLTK_FLAGS = -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/freetype2 -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng16 -g -O2 -fstack-protector-strong -Wformat -Werror=format-security -fvisibility-inlines-hidden -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT -Wl,-Bsymbolic-functions -Wl,-z,relro -Wl,-z,now -Wl,--as-needed -lfltk -lX11 -lfltk_images

OPENCV_FLAGS = -I/usr/include/opencv -lopencv_shape -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_datasets -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hdf -lopencv_line_descriptor -lopencv_optflow -lopencv_video -lopencv_plot -lopencv_reg -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_rgbd -lopencv_viz -lopencv_surface_matching -lopencv_text -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_flann -lopencv_xobjdetect -lopencv_objdetect -lopencv_ml -lopencv_xphoto -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_photo -lopencv_imgproc -lopencv_core

COMPILER_FLAGS = -I$(HEADER_DIRECTORY) $(OPENCV_FLAGS) $(FLTK_FLAGS)

HEADER_DIRECTORY = ./Headers
LIBRARY_DIRECTORY = .
SOURCE_DIRECTORY = ./Sources

LIBRARIES = 

SUB_HEADERS = Motors/GenericMotor.h SessionParameters.h TrackerSession.h
HEADERS = $(patsubst %,$(HEADER_DIRECTORY)/%,$(SUB_HEADERS))

SUB_SOURCES = Main.o HardwareInputs/Camera.o HardwareInputs/Display.o Motors/GenericMotor.o HardwareInputs/InputDevice.o HardwareInputs/InputDeviceSignal.o HardwareInputs/Microphone.o Motors/MotorAC.o Motors/MotorContainer.o Motors/MotorCustom.o Motors/MotorDC.o Motors/MotorDisk.o Motors/MotorServo.o Motors/MotorStepper.o HardwareInputs/Pixel.o SessionParameters.o HardwareInputs/SoundWave.o TrackerSession.o UserInterface/UserInterface.o
SOURCES = $(patsubst %,$(SOURCE_DIRECTORY)/%,$(SUB_SOURCES))

$(SOURCE_DIRECTORY)/%.o: %.c $(HEADERS)
	$(COMPILER) -c -o $@ $< $(COMPILER_FLAGS)

# remove make clean statement as to keep .o files
TrackerSystem: $(SOURCES)
	$(COMPILER) -o $@ $^ $(COMPILER_FLAGS) $(LIBRARIES)
	make clean

.PHONY: clean

clean:
	rm -f $(SOURCE_DIRECTORY)/*.o *~ core $(INCDIR)/*~
	rm -f $(SOURCE_DIRECTORY)/HardwareInputs/*.o *~ core $(INCDIR)/*~
	rm -f $(SOURCE_DIRECTORY)/Motors/*.o *~ core $(INCDIR)/*~
	rm -f $(SOURCE_DIRECTORY)/UserInterface/*.o *~ core $(INCDIR)/*~

