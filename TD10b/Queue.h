#ifndef _FILE_H_
#define _FILE_H_

#include <iostream>
#include "List.h"
using namespace std;

template<typename T>
class Queue : protected List<T>
{
    protected : 
    int nbelem = 0;
    public:
    virtual void put(T a){nbelem++; this->append(a);}
    int get(){nbelem--; return this->get_first();}
    bool is_empty(){return nbelem==0;}
    friend ostream& operator<<(ostream& os, const Queue<T>& q){
        const List<T>& lst = static_cast<const List<T>&>(q);
        os << lst;
        return os;
    }
};

#endif