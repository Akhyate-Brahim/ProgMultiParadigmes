#include "SquareMatrix.h"
#include "DiagonalMatrix.h"
#include "Matrix.h"
#include <cmath>


SquareMatrix operator+(const SquareMatrix &square1, const SquareMatrix &square2) {
    return static_cast<SquareMatrix>(static_cast<Matrix>(square1)+static_cast<Matrix>(square2));
}

Matrix operator+(const Matrix &mat, const SquareMatrix &squareMat) {
    return static_cast<Matrix>(mat+static_cast<Matrix>(squareMat));
}

Matrix operator*(const SquareMatrix &squareMat, const Matrix &mat){
    return static_cast<Matrix>(static_cast<Matrix>(squareMat)*mat);
}

SquareMatrix::SquareMatrix(const Matrix& mat) {
    static_cast<Matrix&>(*this) = mat;
}

double SquareMatrix::det() const {
    int n = nlines(); // or _ncols, they are the same

    if (n == 1) {
        return (*this)(0, 0);
    }
    if (n == 2) {
        return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
    }

    double det = 0.0;
    for (int j = 0; j < n; ++j) {
        SquareMatrix subMatrix(n - 1, n - 1);
        for (int i = 1; i < n; ++i) {
            int col = 0;
            for (int j1 = 0; j1 < n; ++j1) {
                if (j1 == j) continue;
                subMatrix(i - 1, col) = (*this)(i, j1);
                ++col;
            }
        }
        det += std::pow(-1.0, j) * (*this)(0, j) * subMatrix.det();
    }
    return det;
}