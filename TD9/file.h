#ifndef _FILE_H_
#define _FILE_H_

#include <iostream>
#include "list-copy.h"
using namespace std;

class Queue : protected List
{
    protected : 
    int nbelem = 0;
    public:
    virtual void put(int a){nbelem++; append(a);}
    int get(){nbelem--; return get_first();}
    bool is_empty(){return nbelem==0;}
    friend ostream& operator<<(ostream& os, const Queue& q){
        const List& lst = static_cast<const List&>(q);
        os << lst;
        return os;
    }
};

#endif