#include "ScalarMatrix.h"

ScalarMatrix operator+(const ScalarMatrix &scm1, const ScalarMatrix &scm2)
{
    return static_cast<ScalarMatrix>(static_cast<Matrix>(scm1)+static_cast<Matrix>(scm2));
}

ScalarMatrix operator*(const ScalarMatrix &scm1, const ScalarMatrix &scm2)
{
    return static_cast<ScalarMatrix>(static_cast<Matrix>(scm1)*static_cast<Matrix>(scm2));
}

ScalarMatrix::ScalarMatrix(const Matrix &mat){
    static_cast<Matrix&>(*this) = mat;
}
