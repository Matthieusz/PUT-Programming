#include <iostream>
#include "node.h"

using namespace std;

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* next = head->next;
            delete head;
            head = next;
        }
    }

    void add(T data) {
        Node<T>* node = new Node<T>(data);
        if (head == nullptr) {
            head = tail = node;
        } else {
            Node<T>* current = head;
            while (current != nullptr && current->data < data) {
                current = current->next;
            }
            if (current == head) {
                node->next = head;
                head->prev = node;
                head = node;
            } else if (current == nullptr) {
                tail->next = node;
                node->prev = tail;
                tail = node;
            } else {
                node->next = current;
                node->prev = current->prev;
                current->prev->next = node;
                current->prev = node;
            }
        }
    }

    void remove(T data) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                if (current == head) {
                    head = head->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                Node<T>* temp = current;
                current = current->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    template<typename U>
    friend ostream& operator<<(ostream& os, const LinkedList<U>& list);
};

template <typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& list) {
    Node<T>* current = list.tail;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->prev;
    }
    return os;
}
