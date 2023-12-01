
# Makefile for C++ project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Source files
SRC = list-copy.cpp main_LQS.cpp

# Header files
HDR = common_defs.h list-copy.h pile.h file.h fileprior.h

# Target executable
TARGET = main_LQS

# Build rules
all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	chmod +x $(TARGET)
	
clean:
	rm -f $(TARGET)

.PHONY: all clean
