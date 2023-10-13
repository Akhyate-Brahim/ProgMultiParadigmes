# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Target executable with .exe extension
TARGET = main_mvector.exe

# Source files
SRCS = MVector.cpp main_mvector.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Rules

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
