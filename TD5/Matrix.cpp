#include "Matrix.h"

Matrix::Matrix(int rows, int cols, double value)
    : lignes(rows, MVector(cols, value)){}

Matrix::Matrix(int lignes, int colonnes)
    : Matrix(lignes, colonnes, 0.0) {}

bool Matrix::operator==(const Matrix &m) const
{
    if (lignes.size() != m.lignes.size()) {
        return false;
    }
    
    for (size_t i = 0; i < lignes.size(); ++i) {
        if (!(lignes[i] == m.lignes[i]))
        {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &m) const {
    return !(*this == m);
}

Matrix Matrix::operator+(const Matrix &m) const {
    if (lignes.size() != m.lignes.size() || lignes[0].size() != m.lignes[0].size()) {
        throw Bad_Dimensions();
    }
    Matrix result(lignes.size(), lignes[0].size(), 0);
    for (size_t i=0; i<lignes.size(); ++i){
        for (size_t j=0; j < lignes[0].size();++j){
            result.lignes[i][j] = lignes[i][j] + m.lignes[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator-() const {
    Matrix result(lignes.size(), lignes[0].size(), 0);

    for (size_t i = 0; i < lignes.size(); ++i) {
        for (size_t j = 0; j < lignes[0].size(); ++j) {
            result.lignes[i][j] = -lignes[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& m) const{
    if (lignes.size() != m.lignes.size() || lignes[0].size() != m.lignes[0].size()) {
        throw Bad_Dimensions();
    }
    Matrix negM = -m;
    return *this+negM;
}

Matrix& Matrix::operator+=(const Matrix &m) {
    if (lignes.size() != m.lignes.size() || lignes[0].size() != m.lignes[0].size()) {
        throw Bad_Dimensions();
    }
    *this = *this + m;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix&m) {
    if (lignes.size() != m.lignes.size() || lignes[0].size() != m.lignes[0].size()) {
        throw Bad_Dimensions();
    }
    *this = *this - m;
    return *this;
}

Matrix Matrix::operator*(const Matrix &m) const {
    if (lignes[0].size() != m.lignes.size()) {
        throw Bad_Dimensions();
    }
    int rows1 = lignes.size();
    int cols1 = (rows1 > 0) ? lignes[0].size() : 0;
    int rows2 = m.lignes.size();
    int cols2 = (rows2 > 0) ? m.lignes[0].size() : 0;
    Matrix result(rows1, cols2, 0);
    Matrix transposedM = m.transpose();

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result.lignes[i][j] = lignes[i] * transposedM.lignes[j];
        }
    }

    return result;
}
Matrix& Matrix::operator*=(const Matrix&m){
    if (lignes[0].size() != m.lignes.size()) {
        throw Bad_Dimensions();
    }
    *this = *this * m;
    return *this;
}

Matrix Matrix::transpose() const {
    int rows = lignes.size();
    int cols = (rows > 0) ? lignes[0].size() : 0;
    Matrix result(cols, rows, 0);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.lignes[j][i] = lignes[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator~() const
{
    Matrix result = transpose();
    return result;
}

double &Matrix::operator()(int i, int j){
    if (i < 0 || i >= lignes.size() || j < 0 || j >= lignes[0].size()) {
        throw Bad_Index();
    }
    return lignes[i][j];
}

double Matrix::operator()(int i, int j) const {
    if (i < 0 || i >= lignes.size() || j < 0 || j >= lignes[0].size()) {
        throw Bad_Index();
    }
    return lignes[i][j];
}

MVector Matrix::line(int i) const {
    if (i<0 || i>lignes.size()){
        throw Bad_Index();
    }
    return lignes[i];
}

MVector Matrix::column(int i) const {
    Matrix transposeResult = transpose();
    return transposeResult.line(i);
}

Matrix::Matrix(const MVector& mv) {
    lignes.push_back(mv);
}

ostream &operator<<(ostream &o, const Matrix &mat) {
    o << "[" << endl;
    for (const MVector &row : mat.lignes)
    {
        o << row << endl;
    }
    o << "]" << endl;
    return o;
}

Matrix::operator MVector() const {
    if (lignes.size() > 1 && lignes[0].size() > 1) {
        throw Bad_Dimensions();
    }
    if (lignes.size() == 1) {
        return lignes[0];
    } else {
        Matrix transposeMat = this->transpose();
        return transposeMat.lignes[0];
    }
}
