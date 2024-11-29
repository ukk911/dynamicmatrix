#ifndef TRIANGULAR_MATRIX_H
#define TRIANGULAR_MATRIX_H

#include "Matrix.h"

class TriangularMatrix : public Matrix {
public:
    TriangularMatrix(int size, int val);
    TriangularMatrix(const TriangularMatrix& other);
    ~TriangularMatrix();

    int getSize() const;
private:
    int* triangularData;
    int size;
};

#endif
