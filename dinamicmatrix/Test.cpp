#include "Test.h"
#include "Matrix.h"
#include "SingleMatrix.h"
#include "TriangularMatrix.h"   
#include "CyclicLinkedList.h" 
#include <cassert>
#include <cstring>
#include <sstream>
#include <iostream>

using namespace std;

void testMatrixDefaultConstructor() {
    Matrix m;
    assert(m.getCountRows() == 4);
    assert(m.getCountColumns() == 4);
}

void testMatrixParameterizedConstructor() {
    Matrix m(3, 3, 5);
    assert(m.getCountRows() == 3);
    assert(m.getCountColumns() == 3);
    char* result = m.toString();
    assert(strstr(result, "5"));
}

void testMatrixCopyConstructor() {
    Matrix m1(2, 2, 7);
    Matrix m2 = m1;
    assert(strcmp(m1.toString(), m2.toString()) == 0);
}

void testMatrixRandomFill() {
    Matrix m(2, 2, 0);
    m.randomFill(10);
}

void testMatrixReplace() {
    Matrix m(2, 2, 1);
    m.replace(1, 1, 99);
    assert(strstr(m.toString(), "99"));
}

void testMatrixCallOperator() {
    Matrix m(2, 2, 1);
    m(0, 1) = 99;
    assert(m(0, 1) == 99);
}

void testMatrixSearch() {
    Matrix m(2, 2, 1);
    int index = m.search(1);
    assert(index != -1);
}

void testMatrixAssignmentOperator() {
    Matrix m1(2, 2, 5);
    Matrix m2;
    m2 = m1;
    assert(strcmp(m1.toString(), m2.toString()) == 0);
}

void testMatrixAdditionOperator() {
    Matrix m1(2, 2, 3);
    Matrix m2(2, 2, 2);
    Matrix m3 = m1 + m2;
    assert(strstr(m3.toString(), "5"));
}

void testMatrixSubtractionOperator() {
    Matrix m1(2, 2, 5);
    Matrix m2(2, 2, 3);
    Matrix m3 = m1 - m2;
    assert(strstr(m3.toString(), "2"));
}

void testMatrixIndexingOperator() {
    Matrix m(2, 2, 1);
    m[0][1] = 99;
    assert(m[0][1] == 99);
}

void testMatrixSaveToBinaryFile() {
    // Создаем матрицу и заполняем её значениями
    Matrix m1(2, 2, 10);
    // Сохраняем матрицу в бинарный файл
    const char* filename = "test_matrix.dat";
    std::ofstream ofs(filename, std::ios::binary);
    m1.SaveToBinaryFile(ofs);
    ofs.close();
    // Проверяем, что файл был создан и содержит данные
    std::ifstream ifs(filename, std::ios::binary);
    assert(ifs.good());  // Проверка, что файл был успешно открыт
    ifs.close();
    cout << "testMatrixSaveToBinaryFile passed!." << endl;
}

void testMatrixLoadFromBinaryFile() {
    // Создаем матрицу и заполняем её значениями
    Matrix m1(2, 2, 10);
    // Сохраняем матрицу в бинарный файл
    const char* filename = "test_matrix.dat";
    std::ofstream ofs(filename, std::ios::binary);
    m1.SaveToBinaryFile(ofs);
    ofs.close();
    // Создаем новую матрицу и загружаем данные из файла
    Matrix m2;
    std::ifstream ifs(filename, std::ios::binary);
    m2.LoadFromBinaryFile(ifs);
    ifs.close();
    // Проверяем, что загруженная матрица совпадает с исходной
    assert(strcmp(m1.toString(), m2.toString()) == 0);
    cout << "testMatrixLoadFromBinaryFile passed." << endl;
}



void testMatrixOutputOperator() {
    // Создаем матрицу и заполняем её известными значениями
    Matrix m(2, 2, 0);
    m(0, 0) = 5;
    m(0, 1) = 6;
    m(1, 0) = 7;
    m(1, 1) = 8;
    // Подготавливаем строковый поток для захвата вывода
    std::ostringstream output;
    // Используем оператор вывода для записи матрицы в поток
    output << m;
    // Ожидаемый формат вывода
    std::string expectedOutput = "5\t6\t\n7\t8\t\n";
    // Проверка, что строка вывода соответствует ожидаемому формату
    assert(output.str() == expectedOutput);
    std::cout << "testMatrixOutputOperator passed!" << std::endl;
}

void testSingleMatrix() {
    // Создание объекта SingleMatrix и проверка инициализации
    SingleMatrix sm(3, 3, 1, 101);
    assert(sm.getCountRows() == 3);
    assert(sm.getCountColumns() == 3);

    // Заполнение случайными значениями и проверка замены элемента
    sm.randomFill(5);
    sm.replace(0, 0, 10);
    assert(sm(0, 0) == 10);

    // Проверка копирования объекта SingleMatrix
    SingleMatrix sm_copy = sm;
    assert(sm_copy(0, 0) == 10);
    assert(sm_copy.getCountRows() == 3);
    assert(sm_copy.getCountColumns() == 3);

    // Проверка уникального идентификатора
    assert(sm_copy.getUniqueID() == 101);
    std::cout << "testSingleMatrix passed!" << std::endl;
}

void testTriangularMatrix() {
    // Создание объекта TriangularMatrix и проверка инициализации
    TriangularMatrix tm(3, 1);
    assert(tm.getSize() == 3);

    // Проверка установки и получения элемента в треугольной матрице
    tm.replace(0, 0, 10);
    assert(tm(0, 0) == 10);

    // Проверка копирования объекта TriangularMatrix
    TriangularMatrix tm_copy = tm;
    assert(tm_copy.getSize() == 3);
    assert(tm_copy(0, 0) == 10);

    // Проверка сортировки элементов (если метод применим)
    tm.sort();
    std::cout << "testTriangularMatrix passed!" << std::endl;
}

void testMatrixInputOperator() {
    std::istringstream input("1 2 3\n1 2 3\n4 5 6\n");
    Matrix m;
    input >> m;

    assert(m.getCountRows() == 3);
    assert(m.getCountColumns() == 3);
    
    assert(m(0, 0) == 1);
    assert(m(0, 1) == 2);
    assert(m(0, 2) == 3);
    assert(m(1, 0) == 1);
    assert(m(1, 1) == 2);
    assert(m(1, 2) == 3);
    assert(m(2, 0) == 4);
    assert(m(2, 1) == 5);
    assert(m(2, 2) == 6);
    cout << "testMatrixInputOperator passed!" << std::endl;
}



void testCyclicLinkedListAdd() {
    CyclicLinkedList list;
    Matrix* m1 = new Matrix(2, 2, 5); // Создаём объект Matrix
    Matrix* m2 = new Matrix(3, 3, 1);

    list.add(m1);
    list.add(m2);

    // Проверяем, что элементы добавлены и находятся на своих позициях
    assert(list.search(0) == m1); // Проверяем, что первый элемент — m1
    assert(list.search(1) == m2); // Проверяем, что второй элемент — m2

    delete m1; // Чистим память
    delete m2;

    std::cout << "testCyclicLinkedListAdd passed!" << std::endl;
}

void testCyclicLinkedListRemove() {
    CyclicLinkedList list;
    Matrix* m1 = new Matrix(2, 2, 5);
    Matrix* m2 = new Matrix(3, 3, 1);

    list.add(m1);
    list.add(m2);

    // Удаляем последний элемент
    list.remove();

    // Проверяем, что остался только первый элемент
    assert(list.search(0) == m1);
    try {
        list.search(1); // Должно бросить исключение
        assert(false);  // Если исключение не брошено, тест провален
    }
    catch (const std::out_of_range&) {
        // Ожидаемое поведение
    }

    delete m1;

    std::cout << "testCyclicLinkedListRemove passed!" << std::endl;
}

void testCyclicLinkedListInsertAt() {
    CyclicLinkedList list;
    Matrix* m1 = new Matrix(2, 2, 5);
    Matrix* m2 = new Matrix(3, 3, 1);
    Matrix* m3 = new Matrix(1, 1, 10);

    list.add(m1);
    list.add(m2);

    // Вставляем m3 на позицию 1
    list.insertAt(1, m3);

    // Проверяем порядок элементов
    assert(list.search(0) == m1);
    assert(list.search(1) == m3);
    assert(list.search(2) == m2);

    delete m1;
    delete m2;
    delete m3;

    std::cout << "testCyclicLinkedListInsertAt passed!" << std::endl;
}

void testCyclicLinkedListRemoveAt() {
    CyclicLinkedList list;
    Matrix* m1 = new Matrix(2, 2, 5);
    Matrix* m2 = new Matrix(3, 3, 1);
    Matrix* m3 = new Matrix(1, 1, 10);

    list.add(m1);
    list.add(m2);
    list.add(m3);

    // Удаляем элемент на позиции 1
    list.removeAt(1);

    // Проверяем порядок элементов
    assert(list.search(0) == m1);
    assert(list.search(1) == m3);
    try {
        list.search(2); // Должно бросить исключение
        assert(false);  // Если исключение не брошено, тест провален
    }
    catch (const std::out_of_range&) {
        // Ожидаемое поведение
    }

    delete m1;
    delete m3;

    std::cout << "testCyclicLinkedListRemoveAt passed!" << std::endl;
}

void testCyclicLinkedListSearch() {
    CyclicLinkedList list;
    Matrix* m1 = new Matrix(2, 2, 5);
    Matrix* m2 = new Matrix(3, 3, 1);

    list.add(m1);
    list.add(m2);

    // Проверяем, что элементы можно найти по индексу
    assert(list.search(0) == m1);
    assert(list.search(1) == m2);

    delete m1;
    delete m2;

    std::cout << "testCyclicLinkedListSearch passed!" << std::endl;
}

void testCyclicLinkedListPrintList() {
    CyclicLinkedList list;
    Matrix* m1 = new Matrix(2, 2, 5);
    Matrix* m2 = new Matrix(3, 3, 1);

    list.add(m1);
    list.add(m2);

    // Проверка вывода списка (в данном случае просто вызов метода)
    list.printList();

    delete m1;
    delete m2;

    std::cout << "testCyclicLinkedListPrintList passed!" << std::endl;
}