#ifndef MATRIX_H 
#define MATRIX_H

#include <iostream>
#include <fstream>
using namespace std;

class Matrix {
public:
    Matrix();  // ����������� �� ���������
    Matrix(int rows, int columns, int val);  // ����������� � �����������
    Matrix(const Matrix& other);  // ����������� �����������
    ~Matrix();  // ����������

    void randomFill(int max_val);  // ��������� ���������� ����������
    void sort();  // ����������
    void replace(int row, int col, int val);  // ������ ��������
    int search(int val);  // ����� ��������
    int getCountRows() const;  // �������� ���������� �����
    int getCountColumns() const;  // �������� ���������� ��������
    char* toString() const;  // ����� ������� � ������

    static void printName();  // ����������� ������� ��� ������ ����� �������

    Matrix& operator=(const Matrix& other);  // ������������
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);  // ��������
    Matrix operator-(const Matrix& other) const;  // ���������
    int* operator[](int index);  // ��������������
    int& operator()(int row, int col); //����� �������

    void SetRows(int rows);
    void SetColumns(int columns);
    void SetMatrix(int* massive);


    friend std::istream& operator>>(std::istream& is, Matrix& matrix);  // ����
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);  // �����

    // ������ � �������
    
    void SaveToBinaryFile(ofstream& file) const; //������ ������� � �������� ����
    void LoadFromBinaryFile(ifstream& file); //������ ������� �� �������� ����

private:
    static char name_of_matrix[100];  // ����������� ��� �������
    int** matrix;  // ������������ ������
    int count_rows;  // ���������� �����
    int count_columns;  // ���������� ��������
    int _lines;
    int _columns;
    int* _massive;

    void allocateMemory();  // ��������� ������ ��� �������
    void deallocateMemory();  // ������������ ������
};

#endif
