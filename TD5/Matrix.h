#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <vector>
#include "MVector.h"
using namespace std;

class Matrix{
    vector<MVector> lignes;
    public:
    Matrix(){};
    Matrix(int lignes, int colonnes, double valeur);
    Matrix(int lignes, int colonnes);
    Matrix(const MVector& mv);
    bool operator==(const Matrix& m) const;
    bool operator!=(const Matrix& m) const;
    Matrix operator+(const Matrix& m) const;
    Matrix operator-() const;
    Matrix operator-(const Matrix &m) const;
    Matrix& operator+=(const Matrix&m);
    Matrix& operator-=(const Matrix&m);
    Matrix operator*(const Matrix&m) const;
    Matrix& operator*=(const Matrix&m);
    Matrix transpose() const;
    Matrix operator~() const;
    double& operator()(int i, int j);
    double operator()(int i, int j) const;
    MVector line(int i) const;
    MVector column(int i) const;
    friend ostream& operator<<(ostream& o, const Matrix& mat);
    operator MVector() const;
    class Bad_Dimensions{};
    class Bad_Index{};
};
#endif