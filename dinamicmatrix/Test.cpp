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
    // ������� ������� � ��������� � ����������
    Matrix m1(2, 2, 10);
    // ��������� ������� � �������� ����
    const char* filename = "test_matrix.dat";
    std::ofstream ofs(filename, std::ios::binary);
    m1.SaveToBinaryFile(ofs);
    ofs.close();
    // ���������, ��� ���� ��� ������ � �������� ������
    std::ifstream ifs(filename, std::ios::binary);
    assert(ifs.good());  // ��������, ��� ���� ��� ������� ������
    ifs.close();
    cout << "testMatrixSaveToBinaryFile passed!." << endl;
}

void testMatrixLoadFromBinaryFile() {
    // ������� ������� � ��������� � ����������
    Matrix m1(2, 2, 10);
    // ��������� ������� � �������� ����
    const char* filename = "test_matrix.dat";
    std::ofstream ofs(filename, std::ios::binary);
    m1.SaveToBinaryFile(ofs);
    ofs.close();
    // ������� ����� ������� � ��������� ������ �� �����
    Matrix m2;
    std::ifstream ifs(filename, std::ios::binary);
    m2.LoadFromBinaryFile(ifs);
    ifs.close();
    // ���������, ��� ����������� ������� ��������� � ��������
    assert(strcmp(m1.toString(), m2.toString()) == 0);
    cout << "testMatrixLoadFromBinaryFile passed." << endl;
}



void testMatrixOutputOperator() {
    // ������� ������� � ��������� � ���������� ����������
    Matrix m(2, 2, 0);
    m(0, 0) = 5;
    m(0, 1) = 6;
    m(1, 0) = 7;
    m(1, 1) = 8;
    // �������������� ��������� ����� ��� ������� ������
    std::ostringstream output;
    // ���������� �������� ������ ��� ������ ������� � �����
    output << m;
    // ��������� ������ ������
    std::string expectedOutput = "5\t6\t\n7\t8\t\n";
    // ��������, ��� ������ ������ ������������� ���������� �������
    assert(output.str() == expectedOutput);
    std::cout << "testMatrixOutputOperator passed!" << std::endl;
}

void testSingleMatrix() {
    // �������� ������� SingleMatrix � �������� �������������
    SingleMatrix sm(3, 3, 1, 101);
    assert(sm.getCountRows() == 3);
    assert(sm.getCountColumns() == 3);

    // ���������� ���������� ���������� � �������� ������ ��������
    sm.randomFill(5);
    sm.replace(0, 0, 10);
    assert(sm(0, 0) == 10);

    // �������� ����������� ������� SingleMatrix
    SingleMatrix sm_copy = sm;
    assert(sm_copy(0, 0) == 10);
    assert(sm_copy.getCountRows() == 3);
    assert(sm_copy.getCountColumns() == 3);

    // �������� ����������� ��������������
    assert(sm_copy.getUniqueID() == 101);
    std::cout << "testSingleMatrix passed!" << std::endl;
}

void testTriangularMatrix() {
    // �������� ������� TriangularMatrix � �������� �������������
    TriangularMatrix tm(3, 1);
    assert(tm.getSize() == 3);

    // �������� ��������� � ��������� �������� � ����������� �������
    tm.replace(0, 0, 10);
    assert(tm(0, 0) == 10);

    // �������� ����������� ������� TriangularMatrix
    TriangularMatrix tm_copy = tm;
    assert(tm_copy.getSize() == 3);
    assert(tm_copy(0, 0) == 10);

    // �������� ���������� ��������� (���� ����� ��������)
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
    Matrix* m1 = new Matrix(2, 2, 5); // ������ ������ Matrix
    Matrix* m2 = new Matrix(3, 3, 1);

    list.add(m1);
    list.add(m2);

    // ���������, ��� �������� ��������� � ��������� �� ����� ��������
    assert(list.search(0) == m1); // ���������, ��� ������ ������� � m1
    assert(list.search(1) == m2); // ���������, ��� ������ ������� � m2

    delete m1; // ������ ������
    delete m2;

    std::cout << "testCyclicLinkedListAdd passed!" << std::endl;
}

void testCyclicLinkedListRemove() {
    CyclicLinkedList list;
    Matrix* m1 = new Matrix(2, 2, 5);
    Matrix* m2 = new Matrix(3, 3, 1);

    list.add(m1);
    list.add(m2);

    // ������� ��������� �������
    list.remove();

    // ���������, ��� ������� ������ ������ �������
    assert(list.search(0) == m1);
    try {
        list.search(1); // ������ ������� ����������
        assert(false);  // ���� ���������� �� �������, ���� ��������
    }
    catch (const std::out_of_range&) {
        // ��������� ���������
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

    // ��������� m3 �� ������� 1
    list.insertAt(1, m3);

    // ��������� ������� ���������
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

    // ������� ������� �� ������� 1
    list.removeAt(1);

    // ��������� ������� ���������
    assert(list.search(0) == m1);
    assert(list.search(1) == m3);
    try {
        list.search(2); // ������ ������� ����������
        assert(false);  // ���� ���������� �� �������, ���� ��������
    }
    catch (const std::out_of_range&) {
        // ��������� ���������
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

    // ���������, ��� �������� ����� ����� �� �������
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

    // �������� ������ ������ (� ������ ������ ������ ����� ������)
    list.printList();

    delete m1;
    delete m2;

    std::cout << "testCyclicLinkedListPrintList passed!" << std::endl;
}