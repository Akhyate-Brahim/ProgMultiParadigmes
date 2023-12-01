#ifndef _EXPR_CONCRETE_H_
#define _EXPR_CONCRETE_H_

class Constant : public Expr {
    int c;
    public:
    Constant(int a) : c(a) {}
    virtual int eval() const{
        return c;
    }
};

class Unary_Minus : public Unary_Expr{
    int c;
    public:
    Unary_Minus(Expr* exp) : Unary_Expr(exp), c(exp->eval()) {}
    virtual int eval() const{
        return -c;
    }
};

class Binary_Plus : public Binary_Expr{
    int l;
    int r;
    public:
    Binary_Plus(Expr* opl, Expr* opr) : Binary_Expr(opl, opr) , l(opl->eval()), r(opr->eval()){};
    virtual int eval() const{
        return l+r;
    }
};

class Binary_Mult : public Binary_Expr{
    int l;
    int r;
    public:
    Binary_Mult(Expr* opl, Expr* opr) : Binary_Expr(opl, opr) , l(opl->eval()), r(opr->eval()){};
    virtual int eval() const{
        return l*r;
    }
};

class Binary_Div : public Binary_Expr{
    int l;
    int r;
    public:
    Binary_Div(Expr* opl, Expr* opr) : Binary_Expr(opl, opr) , l(opl->eval()), r(opr->eval()){};
    virtual int eval() const{
        if (r==0){
            throw new ZeroDivide();
        }
        return l/r;
    }
};

class Binary_Minus : public Binary_Expr{
    int l;
    int r;
    public:
    Binary_Minus(Expr* opl, Expr* opr) : Binary_Expr(opl, opr) , l(opl->eval()), r(opr->eval()){};
    virtual int eval() const{
        return l-r;
    }
};

class Factoriel : public Unary_Expr{
    int c;
    public:
    Factoriel(Expr* exp) : Unary_Expr(exp), c(exp->eval()) {}
    virtual int eval() const override {
        int result = 1;
        for (int i = 1; i <= c; ++i) {
            result *= i;
        }
        return result;
    }
};

class Binary_Lower : public Binary_Expr{
    int l;
    int r;
    public:
    Binary_Lower(Expr* opl, Expr* opr) : Binary_Expr(opl, opr) , l(opl->eval()), r(opr->eval()){};
    virtual int eval() const{
        return l < r ? 1 : 0;
    }
};

class Binary_Mod : public Binary_Expr{
    int l;
    int r;
    public:
    Binary_Mod(Expr* opl, Expr* opr) : Binary_Expr(opl, opr) , l(opl->eval()), r(opr->eval()){};
    virtual int eval() const{
        return l%r;
    }
};


#endif