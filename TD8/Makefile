
# Makefile for C++ project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Source files
SRC = list-copy.cpp main_list_copy.cpp

# Header files
HDR = common_defs.h list-copy.h

# Target executable
TARGET = main_list_copy

# Build rules
all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	chmod +x $(TARGET)
	
clean:
	rm -f $(TARGET)

.PHONY: all clean
