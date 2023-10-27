#ifndef _DIAGONAL_MATRIX_H_
#define _DIAGONAL_MATRIX_H_

#include <iostream>
#include "SquareMatrix.h"

using namespace std;
class DiagonalMatrix : public SquareMatrix{
    public:
    DiagonalMatrix(int n=0) : SquareMatrix(n){};
    DiagonalMatrix(const MVector &mv);
    friend SquareMatrix operator+=(SquareMatrix& sqMat, const DiagonalMatrix& diagMat);
    friend Matrix operator*(const SquareMatrix& sqMat, const DiagonalMatrix& diagMat);
};
#endif