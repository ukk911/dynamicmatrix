#ifndef CYCLIC_LINKED_LIST_H
#define CYCLIC_LINKED_LIST_H

#include "Matrix.h"
#include <iostream>
#include <stdexcept>

class CyclicLinkedList {
public:
    CyclicLinkedList(); // �����������
    ~CyclicLinkedList(); // ����������

    void add(Matrix* matrix); // �������� ������� � �����
    void remove(); // ������� ��������� �������
    void insertAt(int index, Matrix* matrix); // �������� ������� �� �������
    void removeAt(int index); // ������� ������� �� �������
    Matrix* search(int index); // ����� �������� �� �������
    void printList(); // ������ ���� ��������� ������

private:
    struct Node {
        Matrix* data; // ������ � ���� (������ �� ������ Matrix)
        Node* next; // ��������� �� ��������� �������
    };

    Node* head; // ��������� �� ������ ������� ������
};

#endif
