#include "DiagonalMatrix.h"
#include "SquareMatrix.h"

DiagonalMatrix::DiagonalMatrix(const MVector& mv) : SquareMatrix(mv.size()){
    for (int i = 0; i < mv.size();i++){
        (*this)(i, i) = mv[i];
    }
}

SquareMatrix operator+=(SquareMatrix &sqMat, const DiagonalMatrix &diagMat)
{
    sqMat += static_cast<SquareMatrix>(diagMat);
    return sqMat;
}

Matrix operator*(const SquareMatrix &sqMat, const DiagonalMatrix &diagMat) {
    return static_cast<Matrix>(static_cast<Matrix>(sqMat)*static_cast<Matrix>(diagMat));
}
