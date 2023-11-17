#ifndef _LIST_SIMPLE_H_
#define _LIST_SIMPLE_H_
#include <iostream>
using namespace std;

struct Element{
    int data;
    Element* next;
    Element(int n, Element* ptr=0) : data(n), next(ptr){}
};

class List{
    Element* start;
    Element* end;
    public:
    List() : start(0), end(0) {}
    List(const List& list);
    void append(int i);
    void prepend(int i);
    bool is_empty();
    int get_first();
    int get_last();
    class EmptyListException{};
    void insert(int i);
    void sort();
    int get_middle_value();
    int& max();
    void mirror();
    List& operator=(const List& list);
    ~List();
    List operator+(const List& list);
    List operator*(const List& list);
    friend ostream& operator<<(ostream& o,const List& list);
};

#endif
