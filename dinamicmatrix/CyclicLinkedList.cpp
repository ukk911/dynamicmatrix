#include "CyclicLinkedList.h"

CyclicLinkedList::CyclicLinkedList() : head(nullptr) {}

CyclicLinkedList::~CyclicLinkedList() {
    if (head) {
        Node* current = head;
        do {
            Node* temp = current;
            current = current->next;
            delete temp->data;
            delete temp;
        } while (current != head);
    }
}

void CyclicLinkedList::add(Matrix* matrix) {
    Node* newNode = new Node;
    newNode->data = matrix;
    if (!head) {
        head = newNode;
        head->next = head; // Указываем, что список цикличен
    }
    else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Вставляем новый элемент в конец и делаем список цикличным
    }
}

void CyclicLinkedList::remove() {
    if (head) {
        if (head->next == head) {
            delete head->data;
            delete head;
            head = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Node* toDelete = head;
            head = head->next;
            temp->next = head;
            delete toDelete->data;
            delete toDelete;
        }
    }
}

void CyclicLinkedList::insertAt(int index, Matrix* matrix) {
    if (index < 0) throw std::out_of_range("Index cannot be negative");
    Node* newNode = new Node;
    newNode->data = matrix;
    if (index == 0) {
        newNode->next = head;
        if (head) {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        head = newNode;
    }
    else {
        Node* temp = head;
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
            if (!temp || temp->next == head) throw std::out_of_range("Index out of range");
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void CyclicLinkedList::removeAt(int index) {
    if (index < 0) throw std::out_of_range("Index cannot be negative");
    if (head) {
        if (index == 0) {
            remove();
        }
        else {
            Node* temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
                if (!temp || temp->next == head) throw std::out_of_range("Index out of range");
            }
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete->data;
            delete toDelete;
        }
    }
}


Matrix* CyclicLinkedList::search(int index) {
    if (index < 0) {
        throw std::out_of_range("Index cannot be negative");
    }
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    Node* temp = head;
    int count = 0;
    do {
        if (count == index) {
            return temp->data;
        }
        //temp = temp->next;
        count++;
    } while (temp != head); // Циклический обход

    //throw std::out_of_range("Index out of range");
}

void CyclicLinkedList::printList() {
    if (!head) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node* temp = head;
    do {
        std::cout << temp->data->toString() << std::endl;
        temp = temp->next;
    } while (temp != head);
}