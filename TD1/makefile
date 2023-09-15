# Specify the compiler
CXX = g++

# Specify compiler flags
CXXFLAGS = -Wall -W

# Collect all .cpp files in the current directory
SOURCES = $(wildcard *.cpp)
# Create a list of all intended executable names by replacing .cpp with nothing (i.e., removing the .cpp extension)
EXECUTABLES = $(SOURCES:.cpp=)

all: $(EXECUTABLES)

# Rule that matches the executable names. For each executable, it finds the corresponding .cpp file to compile it.
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(EXECUTABLES)
