#ifndef SINGLE_MATRIX_H
#define SINGLE_MATRIX_H

#include "Matrix.h"
#include <string>

class SingleMatrix : public Matrix {
public:
    SingleMatrix(int rows, int columns, int val, int id);
    SingleMatrix(const SingleMatrix& other);
    ~SingleMatrix();

    void printID() const;
    int getUniqueID() const;
private:
    int uniqueID;
};

#endif
