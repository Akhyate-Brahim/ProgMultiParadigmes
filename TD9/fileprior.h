#ifndef _PRIOR_QUEUE_H_
#define _PRIOR_QUEUE_H_

#include <iostream>
#include "list-copy.h"
using namespace std;

class Priority_Queue : public Queue
{
    public:
    virtual void put(int i){nbelem++; insert(i);} // utiliser le type dynamique initialement vers Queue puis vers Priority_Queue
    friend ostream& operator<<(ostream& os, const Priority_Queue& q) {
        const Queue& que = static_cast<const Queue&>(q);
        os << que;
        return os;  
    }
};

#endif