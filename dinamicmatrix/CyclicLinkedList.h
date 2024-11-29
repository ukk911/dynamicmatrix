#ifndef CYCLIC_LINKED_LIST_H
#define CYCLIC_LINKED_LIST_H

#include "Matrix.h"
#include <iostream>
#include <stdexcept>

class CyclicLinkedList {
public:
    CyclicLinkedList(); // Конструктор
    ~CyclicLinkedList(); // Деструктор

    void add(Matrix* matrix); // Добавить элемент в конец
    void remove(); // Удалить последний элемент
    void insertAt(int index, Matrix* matrix); // Вставить элемент по индексу
    void removeAt(int index); // Удалить элемент по индексу
    Matrix* search(int index); // Поиск элемента по индексу
    void printList(); // Печать всех элементов списка

private:
    struct Node {
        Matrix* data; // Данные в узле (ссылка на объект Matrix)
        Node* next; // Указатель на следующий элемент
    };

    Node* head; // Указатель на первый элемент списка
};

#endif
