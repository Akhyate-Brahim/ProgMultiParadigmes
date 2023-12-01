
# Makefile for C++ project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Source files
SRC = tst_menu.cpp menu.cpp

# Header files
HDR = menu_item.h menu.h simple_menu_item.h walking_item.h

# Target executable
TARGET = tst_menu

# Build rules
all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	chmod +x $(TARGET)
	
clean:
	rm -f $(TARGET)

.PHONY: all clean
