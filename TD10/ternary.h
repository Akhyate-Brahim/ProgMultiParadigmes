#ifndef _TERNARY_H_
#define _TERNARY_H_

#include <iostream>
#include "expr-abstract.h"

class Ternary_Conditional : public Expr{
    int condition;
    int r1;
    int r2;
    public:
    Ternary_Conditional(Expr* cond, Expr* res1, Expr* res2) :  condition(cond->eval()), r1(res1->eval()), r2(res2->eval()){}
    int eval() const{
        return condition == 1 ? r1 : r2;
    }
};

#endif