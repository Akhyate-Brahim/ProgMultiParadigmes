#ifndef _PILE_H_
#define _PILE_H_

#include <iostream>
#include "List.h"
using namespace std;

template<typename T>
class Stack : private List<T>
{
    int nbelem = 0;
    public:
    void push(T a){nbelem++; this->prepend(a);}
    int pop(){nbelem--; return this->get_first();}
    bool is_empty(){return nbelem==0;}
    friend ostream& operator<<(ostream& os, const Stack<T>& s){
        const List<T>& lst = static_cast<const List<T>&>(s);
        os << lst;
        return os;
    }
};

#endif