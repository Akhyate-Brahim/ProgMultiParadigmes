
# Makefile for C++ project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Source files
SRC = main_matrix.cpp MVector.cpp Matrix.cpp

# Header files
HDR = MVector.h Matrix.h common_defs.h

# Target executable
TARGET = main_matrix

# Build rules
all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	chmod +x $(TARGET)
	
clean:
	rm -f $(TARGET)

.PHONY: all clean
