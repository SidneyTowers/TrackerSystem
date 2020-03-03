############################################################
#	 Makefile for TrackerSystem creation simplification    #
#                  author: Sidney Towers                   #
############################################################

IDIR = .
CC = g++
CFLAGS = -I$(IDIR)

# cannot seem to get it to store .o files within another folder
ODIR = .
LDIR = .

LIBS = 

_DEPS = GenericMotor.h SessionParameters.h TrackerSession.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Starter.o Camera.o Display.o GenericMotor.o InputDevice.o InputDeviceSignal.o Microphone.o MotorAC.o MotorContainer.o MotorCustom.o MotorDC.o MotorDisk.o MotorServo.o MotorStepper.o Pixel.o SessionParameters.o SoundWave.o TrackerSession.o UserInterface.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# remove make clean statement as to keep .o files
TrackerSystem: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	make clean

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
