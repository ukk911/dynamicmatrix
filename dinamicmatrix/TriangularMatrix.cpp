#include "TriangularMatrix.h"
#include <iostream>

TriangularMatrix::TriangularMatrix(int size, int val) : Matrix(size, size, 0), size(size) {
    triangularData = new int[size * (size + 1) / 2];
    for (int i = 0; i < size * (size + 1) / 2; ++i) {
        triangularData[i] = val;
    }
}

TriangularMatrix::TriangularMatrix(const TriangularMatrix& other) : Matrix(other), size(other.size) {
    triangularData = new int[size * (size + 1) / 2];
    std::copy(other.triangularData, other.triangularData + size * (size + 1) / 2, triangularData);
}

TriangularMatrix::~TriangularMatrix() {
    delete[] triangularData;
}

int TriangularMatrix::getSize() const {
    return size;
}