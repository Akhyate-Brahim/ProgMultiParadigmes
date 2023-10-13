#include <iostream>
#include <vector>
#include <cmath>
#include "MVector.h"
using namespace std;

MVector::MVector() : data(){}

MVector::MVector(int a, double x) : data(a, x){}

MVector::MVector(vector<double> newData) : data(newData){}

bool MVector::operator==(const MVector& other) const {
    return data == other.data;
}

double MVector::operator[](int i) const {
    if (i < 0 || i >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return data[i];
}

double& MVector::operator[](int i) {
    if (i < 0 || i >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return data[i];
}

MVector& MVector::operator=(MVector other) {
    data = other.data;
    return *this;
}

MVector& MVector::operator++() {
    for (double& val : data) {
        ++val;
    }
    return *this;
}

MVector& MVector::operator++(int) {
    MVector temp = *this;
    for (double& val : data) {
        val++;
    }
    return temp;
}

MVector& MVector::operator--() {
    for (double& val : data) {
        --val;
    }
    return *this;
}

MVector& MVector::operator--(int) {
    MVector temp = *this;
    for (double& val : data) {
        val--;
    }
    return temp;
}

MVector MVector::operator+(MVector other) {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Vectors must be of the same size for addition");
    }
    MVector result = *this;
    for (int i = 0; i < data.size(); ++i) {
        result.data[i] += other.data[i];
    }
    return result;
}

MVector& MVector::operator+=(MVector other) {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Vectors must be of the same size for addition");
    }
    for (int i = 0; i < data.size(); ++i) {
        data[i] += other.data[i];
    }
    return *this;
}

MVector MVector::operator-(MVector other) {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Vectors must be of the same size for subtraction");
    }
    MVector result = *this;
    for (int i = 0; i < data.size(); ++i) {
        result.data[i] -= other.data[i];
    }
    return result;
}

MVector& MVector::operator-=(MVector other) {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Vectors must be of the same size for subtraction");
    }
    for (int i = 0; i < data.size(); ++i) {
        data[i] -= other.data[i];
    }
    return *this;
}

double MVector::operator*(const MVector& other) const {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Vectors must be of the same size for the dot product");
    }

    double dotProduct = 0.0;
    for (size_t i = 0; i < data.size(); ++i) {
        dotProduct += data[i] * other.data[i];
    }

    return dotProduct;
}
double MVector::norm() {
    double sum = 0.0;
    for (double val : data) {
        sum += val * val;
    }
    return std::sqrt(sum);
}
double operator*(const std::vector<double>& vec, const MVector& mVec) {
    if (vec.size() != mVec.data.size()) {
        throw std::invalid_argument("Vectors must be of the same size for the dot product");
    }

    double dotProduct = 0.0;
    for (size_t i = 0; i < vec.size(); ++i) {
        dotProduct += vec[i] * mVec[i];
    }

    return dotProduct;
}


ostream& operator<<(ostream& o, MVector mVector) {
    o << "[";
    for (const auto& val : mVector.data) {
        o << val << " ";
    }
    o << "]";
    return o;
}
