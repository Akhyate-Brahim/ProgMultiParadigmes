# Makefile for C++ project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Source files for main_list
SRC_MAIN_LIST = main_list.cpp

# Source files for main_LQS
SRC_MAIN_LQS = main_LQS.cpp

# Header files (common for both targets)
HDR = common_defs.h List.h Priority_Queue.h Queue.h Stack.h

# Target executables
TARGET_MAIN_LIST = main_list
TARGET_MAIN_LQS = main_LQS

# Build rules
all: $(TARGET_MAIN_LIST) $(TARGET_MAIN_LQS)

$(TARGET_MAIN_LIST): $(SRC_MAIN_LIST) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC_MAIN_LIST) -o $(TARGET_MAIN_LIST)

$(TARGET_MAIN_LQS): $(SRC_MAIN_LQS) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC_MAIN_LQS) -o $(TARGET_MAIN_LQS)

clean:
	rm -f $(TARGET_MAIN_LIST) $(TARGET_MAIN_LQS)

.PHONY: all clean