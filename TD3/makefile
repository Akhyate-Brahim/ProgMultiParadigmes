FLAGS = -W -Wall
CXX = g++

all: main_date.exec

main_date.exec: date.o main_date.o
	$(CXX) $(FLAGS) date.o main_date.o -o main_date.exec

date.o: date.cpp date.h common_defs.h
	$(CXX) $(FLAGS) -c date.cpp -o date.o

main_date.o: main_date.cpp date.h common_defs.h
	$(CXX) $(FLAGS) -c main_date.cpp -o main_date.o

clean:
	rm -rf *.o main_date.exec
