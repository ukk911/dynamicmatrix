#ifndef MATRIX_H 
#define MATRIX_H

#include <iostream>
#include <fstream>
using namespace std;

class Matrix {
public:
    Matrix();  // Конструктор по умолчанию
    Matrix(int rows, int columns, int val);  // Конструктор с параметрами
    Matrix(const Matrix& other);  // Конструктор копирования
    ~Matrix();  // Деструктор

    void randomFill(int max_val);  // Заполнить случайными значениями
    void sort();  // Сортировка
    void replace(int row, int col, int val);  // Замена элемента
    int search(int val);  // Поиск элемента
    int getCountRows() const;  // Получить количество строк
    int getCountColumns() const;  // Получить количество столбцов
    char* toString() const;  // Вывод матрицы в строку

    static void printName();  // Статическая функция для вывода имени матрицы

    Matrix& operator=(const Matrix& other);  // Присваивание
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);  // Сложение
    Matrix operator-(const Matrix& other) const;  // Вычитание
    int* operator[](int index);  // Индексирование
    int& operator()(int row, int col); //Вызов функции

    void SetRows(int rows);
    void SetColumns(int columns);
    void SetMatrix(int* massive);


    friend std::istream& operator>>(std::istream& is, Matrix& matrix);  // Ввод
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);  // Вывод

    // Работа с файлами
    
    void SaveToBinaryFile(ofstream& file) const; //запись объекта в двоичный файл
    void LoadFromBinaryFile(ifstream& file); //запись объекта из двоичный файл

private:
    static char name_of_matrix[100];  // Статическое имя матрицы
    int** matrix;  // Динамический массив
    int count_rows;  // Количество строк
    int count_columns;  // Количество столбцов
    int _lines;
    int _columns;
    int* _massive;

    void allocateMemory();  // Выделение памяти под матрицу
    void deallocateMemory();  // Освобождение памяти
};

#endif
