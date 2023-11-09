
# Makefile for C++ project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Source files
SRC = list_simple.cpp main_list_simple.cpp

# Header files
HDR = common_defs.h list_simple.h

# Target executable
TARGET = main_list_simple

# Build rules
all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	chmod +x $(TARGET)
	
clean:
	rm -f $(TARGET)

.PHONY: all clean
