#include "SingleMatrix.h"
#include <iostream>

SingleMatrix::SingleMatrix(int rows, int columns, int val, int id)
    : Matrix(rows, columns, val), uniqueID(id) {}

SingleMatrix::SingleMatrix(const SingleMatrix& other)
    : Matrix(other), uniqueID(other.uniqueID) {}

SingleMatrix::~SingleMatrix() {}

void SingleMatrix::printID() const {
    std::cout << "Single Matrix ID: " << uniqueID << std::endl;
}
int SingleMatrix::getUniqueID() const {
    return uniqueID;
}