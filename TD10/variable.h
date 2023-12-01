#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include "expr-abstract.h"
#include <map>

static map<string, int> var_table;

class Variable_Ref : public Expr{
    string nom_variable;
    public:
    Variable_Ref(string nom, Expr* expr = nullptr) : nom_variable(nom){
        if (expr == nullptr){
            var_table[nom] = 0;
        } else{
            var_table[nom] = expr->eval();
        }
    }
    virtual int eval() const{
        return var_table[nom_variable];
    }
    string getNomVariable(){
        return nom_variable;
    }
};

class Assignment : public Expr{
    string variable;
    int valeur;
    public:
    Assignment(Variable_Ref* var, Expr* exp) : variable(var->getNomVariable()) , valeur(exp->eval()){}
    virtual int eval() const{
        var_table[variable] = valeur;
        return var_table[variable];
    }
};

class plusplus_prefix : public Expr{
    string variable;
    public:
    plusplus_prefix(Variable_Ref* var) : variable(var->getNomVariable()){}
    virtual int eval() const{
        var_table[variable]++;
        return var_table[variable];
    }
};

class plusplus_postfix : public Expr{
    string variable;
    public:
    plusplus_postfix(Variable_Ref* var) : variable(var->getNomVariable()){}
    virtual int eval() const{
        int a = var_table[variable];
        var_table[variable]++;
        return a;
    }
};

#endif