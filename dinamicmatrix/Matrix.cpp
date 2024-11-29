#include "Matrix.h"
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

char Matrix::name_of_matrix[100] = "MatrixA";

Matrix::Matrix() : count_rows(4), count_columns(4) {
    allocateMemory();
    for (int i = 0; i < count_rows; ++i)
        for (int j = 0; j < count_columns; ++j)
            matrix[i][j] = 0;
}

Matrix::Matrix(int rows, int columns, int val) : count_rows(rows), count_columns(columns) {
    allocateMemory();
    for (int i = 0; i < count_rows; ++i)
        for (int j = 0; j < count_columns; ++j)
            matrix[i][j] = val;
}

Matrix::Matrix(const Matrix& other) : count_rows(other.count_rows), count_columns(other.count_columns) {
    allocateMemory();
    for (int i = 0; i < count_rows; ++i)
        for (int j = 0; j < count_columns; ++j)
            matrix[i][j] = other.matrix[i][j];
}

Matrix::~Matrix() {
    deallocateMemory();
}

void Matrix::allocateMemory() {
    matrix = new int* [count_rows];
    for (int i = 0; i < count_rows; ++i)
        matrix[i] = new int[count_columns];
}

void Matrix::deallocateMemory() {
    if (matrix) {
        for (int i = 0; i < count_rows; ++i)
            delete[] matrix[i];
        delete[] matrix;
        matrix = nullptr;
    }
}

void Matrix::randomFill(int max_val) {
    srand(time(nullptr));
    for (int i = 0; i < count_rows; ++i)
        for (int j = 0; j < count_columns; ++j)
            matrix[i][j] = rand() % max_val;
}

void Matrix::sort() {
    for (int i = 0; i < count_rows; ++i) {
        for (int j = 0; j < count_columns - 1; ++j) {
            for (int k = j + 1; k < count_columns; ++k) {
                if (matrix[i][j] > matrix[i][k]) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][k];
                    matrix[i][k] = temp;
                }
            }
        }
    }
}

void Matrix::replace(int row, int col, int val) {
    if (row < count_rows && col < count_columns) {
        matrix[row][col] = val;
    }
}

int Matrix::search(int val) {
    for (int i = 0; i < count_rows; ++i) {
        for (int j = 0; j < count_columns; ++j) {
            if (matrix[i][j] == val)
                return i * count_columns + j;
        }
    }
    return -1;
}

int Matrix::getCountRows() const {
    return count_rows;
}

int Matrix::getCountColumns() const {
    return count_columns;
}

char* Matrix::toString() const {
    static char buffer[1024];
    strcpy(buffer, "");
    for (int i = 0; i < count_rows; ++i) {
        for (int j = 0; j < count_columns; ++j) {
            char temp[10];
            sprintf(temp, "%d\t", matrix[i][j]);
            strcat(buffer, temp);
        }
        strcat(buffer, "\n");
    }
    return buffer;
}



void Matrix::printName() {
    cout << name_of_matrix << endl;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    deallocateMemory();
    count_rows = other.count_rows;
    count_columns = other.count_columns;
    allocateMemory();
    for (int i = 0; i < count_rows; ++i)
        for (int j = 0; j < count_columns; ++j)
            matrix[i][j] = other.matrix[i][j];
    return *this;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.count_rows != rhs.count_rows || lhs.count_columns != rhs.count_columns)
        throw std::invalid_argument("Matrices must have the same size!");
    Matrix result(lhs.count_rows, lhs.count_columns, 0);
    for (int i = 0; i < lhs.count_rows; ++i)
        for (int j = 0; j < lhs.count_columns; ++j)
            result.matrix[i][j] = lhs.matrix[i][j] + rhs.matrix[i][j];
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (count_rows != other.count_rows || count_columns != other.count_columns)
        throw std::invalid_argument("Matrices must have the same size!");
    Matrix result(count_rows, count_columns, 0);
    for (int i = 0; i < count_rows; ++i)
        for (int j = 0; j < count_columns; ++j)
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
    return result;
}

int* Matrix::operator[](int index) {
    if (index < 0 || index >= count_rows)
        throw std::out_of_range("Index is out of range!");
    return matrix[index];
}

int& Matrix::operator()(int row, int col) {
    if (row < 0 || row >= count_rows || col < 0 || col >= count_columns) {
        throw std::out_of_range("Index is out of range!");
    }
    return matrix[row][col];
}


void Matrix::SetRows(int rows) {
    count_rows = rows;
}

void Matrix::SetColumns(int columns) {
    count_columns = columns;
}


void Matrix::SetMatrix(int* massive) {
    // Deallocate previously allocated memory, if any
    if (matrix) {
        for (int i = 0; i < count_rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // Allocate memory for rows
    matrix = new int* [count_rows];
    for (int i = 0; i < count_rows; ++i) {
        matrix[i] = new int[count_columns]; // Allocate memory for each row
    }

    // Copy data from the flat array into the 2D matrix
    for (int i = 0; i < count_rows; ++i) {
        for (int j = 0; j < count_columns; ++j) {
            matrix[i][j] = massive[i * count_columns + j];
        }
    }
}





//вывод
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.count_rows; ++i) {
        for (int j = 0; j < matrix.count_columns; ++j) {
            os << matrix.matrix[i][j] << "\t";
        }
        os << std::endl;
    }
    return os;
}

//ввод
std::istream& operator>>(std::istream& is, Matrix& m) {
    std::vector<std::vector<int>> tempMatrix;
    std::string line;
    int columns = 0;

    while (std::getline(is, line)) {
        std::istringstream lineStream(line);
        std::vector<int> row;
        int value;

        while (lineStream >> value) {
            row.push_back(value);
        }

        if (!row.empty()) {
            if (columns == 0) {
                columns = row.size();  // Set columns for the first row
            }
            else if (columns != row.size()) {
                throw std::runtime_error("Inconsistent number of columns in input.");
            }
            tempMatrix.push_back(row);
        }
    }

    // Check if matrix is empty
    if (tempMatrix.empty()) {
        throw std::runtime_error("Empty matrix input.");
    }

    // Set the matrix dimensions and values
    int rows = tempMatrix.size();
    m.SetRows(rows);
    m.SetColumns(columns);

    // Flatten the 2D vector into a 1D array if your matrix class requires that
    std::vector<int> flatMatrix;
    for (const auto& row : tempMatrix) {
        flatMatrix.insert(flatMatrix.end(), row.begin(), row.end());
    }

    // Set the 2D matrix using the flattened array
    m.SetMatrix(flatMatrix.data());

    return is;
}





void Matrix::SaveToBinaryFile(ofstream& file) const {
    file.write(reinterpret_cast<const char*>(&count_rows), sizeof(count_rows));
    file.write(reinterpret_cast<const char*>(&count_columns), sizeof(count_columns));
    for (int i = 0; i < count_rows; ++i)
        file.write(reinterpret_cast<const char*>(matrix[i]), count_columns * sizeof(int));
}

void Matrix::LoadFromBinaryFile(ifstream& file) {
    file.read(reinterpret_cast<char*>(&count_rows), sizeof(count_rows));
    file.read(reinterpret_cast<char*>(&count_columns), sizeof(count_columns));
    deallocateMemory();
    allocateMemory();
    for (int i = 0; i < count_rows; ++i)
        file.read(reinterpret_cast<char*>(matrix[i]), count_columns * sizeof(int));
}
