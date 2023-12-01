#ifndef _PILE_H_
#define _PILE_H_

#include <iostream>
#include "list-copy.h"
using namespace std;

class Stack : private List
{
    int nbelem = 0;
    public:
    void push(int a){nbelem++; prepend(a);}
    int pop(){nbelem--; return get_first();}
    bool is_empty(){return nbelem==0;}
    friend ostream& operator<<(ostream& os, const Stack& s){
        const List& lst = static_cast<const List&>(s);
        os << lst;
        return os;
    }
};

#endif