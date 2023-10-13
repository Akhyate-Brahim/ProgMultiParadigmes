#include <iostream>
#include <vector>
#ifndef MVECTOR_H
#define MVECTOR_H
using namespace std;
class MVector{
    vector<double> data;
    public:
    // constructors
    MVector();
    MVector(int a,double x);
    MVector(vector<double> newData);
    // operators
    bool operator==(const MVector& other) const;
    double operator[](int i) const;
    double& operator[](int i);
    MVector& operator=(MVector other);
    MVector& operator++();
    MVector operator+(MVector other);
    MVector& operator--();
    MVector operator-(MVector other);
    MVector& operator+=(MVector other);
    MVector& operator-=(MVector other);
    MVector& operator++(int);
    MVector& operator--(int);
    double operator*(const MVector& other) const;
    // member functions
    double norm();
    // friend functions
    friend ostream& operator<<(ostream&o,MVector mVector); // for syntaxic reasons
    friend double operator*(const std::vector<double>& lhs, const MVector& rhs); // for implicit conversion reasons

    // The line cmv[2] = 3.5; does not compile because cmv is a constant object, and the operator[] used is the constant version
};
#endif