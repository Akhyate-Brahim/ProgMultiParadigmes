#ifndef _LIST_SIMPLE_H_
#define _LIST_SIMPLE_H_
#include <iostream>
using namespace std;

struct Element{
    int data;
    Element* next;
    Element(int n) : data(n){}
};

class List{
    Element* base;
    public:
    List() : base(nullptr) {}
    void append(int i);
    void prepend(int i);
    bool is_empty();
    int get_first();
    class EmptyListException{};
    void insert(int i);

    friend ostream& operator<<(ostream& o, List list);
};

#endif