BIN = bin
CPPSRC = src/cpp
WEBAPP = src/webapp
RSRC = resources

#-----------------------------------------------#

# Target
CPP_TARGET = $(BIN)/a.out

# compiler, flags, libs
CXX = g++
CXXFLAGS = -std=c++11 -pthread
OPENCV = `pkg-config --cflags --libs opencv4`

# Sources
RELEASE_SRC = $(CPPSRC)/common.cpp $(CPPSRC)/admin.cpp $(CPPSRC)/ml.cpp $(CPPSRC)/socket.cpp $(CPPSRC)/uploader.cpp $(CPPSRC)/main.cpp
DEBUG_SRC =  $(CPPSRC)/common.cpp $(CPPSRC)/admin.cpp $(CPPSRC)/ml.cpp $(CPPSRC)/test.cpp $(CPPSRC)/uploader.cpp $(CPPSRC)/main.cpp

# Task options
OPT = #-DDIVIDE
#-----------------------------------------------#

# Compile: release version

all: $(CPP_TARGET)
	@echo "Compile is done! Run with 'make run'"

$(CPP_TARGET):
	$(CXX) $(CXXFLAGS) $(OPT) $(RELEASE_SRC) $(OPENCV) -o $(CPP_TARGET)

#-----------------------------------------------#

# Compile: debug version

debug: $(CPP_TARGET)
	@echo "Compile is done! Run with 'make debug_run'"

$(CPP_TARGET):
	$(CXX) $(CXXFLAGS) $(OPT) $(DEBUG_SRC) $(OPENCV) -o $(CPP_TARGET)

#-----------------------------------------------#

# Run

run:
	node $(WEBAPP)/server.js

#-----------------------------------------------#

# Make init and Remove target file

clean:
	rm -f $(BIN)/*.out

#-----------------------------------------------#

# Remove all subdirs and files in $(WEB_ROOT)

init:
	rm -rf $(RSRC)
	mkdir $(RSRC)
	mkdir $(RSRC)/images
	touch $(RSRC)/camera_ip.txt
	touch $(RSRC)/people.txt

#-----------------------------------------------#

# for myself
update:
	git add .
	git commit -m "debugging"
	git push -u mac master

#-----------------------------------------------#
