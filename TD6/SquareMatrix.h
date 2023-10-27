#ifndef _SQUARE_MATRIX_H_
#define _SQUARE_MATRIX_H_

#include <iostream>
#include "Matrix.h"

using namespace std;
class SquareMatrix : public Matrix{
    public:
    SquareMatrix(int n=0, double x=0.0) : Matrix(n,n,x){}    // SquareMatrix(MVector mv, bool transp = false) : Matrix(mv,transp){}
    friend SquareMatrix operator+(const SquareMatrix& square1,const SquareMatrix& square2);
    friend Matrix operator+(const Matrix& mat, const SquareMatrix& squareMat);
    friend Matrix operator*(const SquareMatrix& squareMat, const Matrix& mat);
    SquareMatrix(const Matrix& mat);
    double det() const;
};
#endif