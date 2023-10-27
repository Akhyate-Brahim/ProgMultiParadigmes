#ifndef _SCALAR_MATRIX_H_
#define _SCALAR_MATRIX_H_

#include <iostream>
#include "DiagonalMatrix.h"

using namespace std;
class ScalarMatrix : public DiagonalMatrix{
    public:
    ScalarMatrix(int n=0) : DiagonalMatrix(n){};
    ScalarMatrix(int n, double d) : DiagonalMatrix(MVector(n, d)) {};
    ScalarMatrix(const Matrix& mat);
    friend ScalarMatrix operator+(const ScalarMatrix& scm1,const ScalarMatrix& scm2); 
    friend ScalarMatrix operator*(const ScalarMatrix& scm1,const ScalarMatrix& scm2); 
};
#endif