
CXX=arm-linux-gnueabihf-g++

INCLUDEDIR = ./ 
INCLUDEDIR += $(HOME)/rpi/mntrpi/usr/include/qt4/
INCLUDEDIR += $(HOME)/rpi/mntrpi/usr/include/qt4/QtGui

LIBRARYDIR = $(HOME)/rpi/mntrpi/usr/lib/arm-linux-gnueabihf/
LIBRARY +=  QtCore QtGui 
XLINK_LIBDIR += $(HOME)/rpi/mntrpi/lib/arm-linux-gnueabihf
XLINK_LIBDIR += $(HOME)/rpi/mntrpi/usr/lib/arm-linux-gnueabihf

INCDIR  = $(patsubst %,-I%,$(INCLUDEDIR))
LIBDIR  = $(patsubst %,-L%,$(LIBRARYDIR))
LIB    = $(patsubst %,-l%,$(LIBRARY))
XLINKDIR = $(patsubst %,-Xlinker -rpath-link=%,$(XLINK_LIBDIR))
 
OPT = -O0
DEBUG = -g
WARN= -Wall
PTHREAD= -pthread

CXXFLAGS= $(OPT) $(DEBUG) $(WARN) $(INCDIR)
LDFLAGS= $(LIBDIR) $(LIB) $(XLINKDIR) $(PTHREAD)

INC = qttest.h 
SRC = main.cpp qttest.cpp

OBJ = $(SRC:.cpp=.o) $(INC:.h=.moc.o)


all: $(OBJ)
	$(CXX) $(LDFLAGS) $(OBJ) -o target_bin


%.moc.cpp: $(INC)
	moc-qt4  $<  -o $@

%.o:%.cpp
	$(CXX) $(CXXFLAGS)  -c $<  

clean:
	-rm *.o
	-rm target_bin

