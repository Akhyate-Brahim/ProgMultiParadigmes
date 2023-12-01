#ifndef _PRIOR_QUEUE_H_
#define _PRIOR_QUEUE_H_

#include <iostream>
#include "List.h"
using namespace std;
template<typename T>
class Priority_Queue : public Queue<T>
{
    public:
    virtual void put(T i){this->nbelem++; this->insert(i);}
    friend ostream& operator<<(ostream& os, const Priority_Queue<T>& q) {
        const Queue<T>& que = static_cast<const Queue<T>&>(q);
        os << que;
        return os;  
    }
};

#endif