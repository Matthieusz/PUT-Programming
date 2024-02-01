#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
class Node {
    public:
        Node(T data);
        ~Node();
        T getData();
        void setData(T data);
        Node<T>*& getLeft();
        void setLeft(Node<T>* left);
        Node<T>*& getRight();
        void setRight(Node<T>* right);
    private:
        T data;
        Node<T>* left;
        Node<T>* right;
};

template<class T>
Node<T>::Node(T data) : data(data), left(nullptr), right(nullptr) {}

template<class T>
Node<T>::~Node() {
    delete left;
    delete right;
}

template<class T>
T Node<T>::getData() {
    return data;
}

template<class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template<class T>
Node<T>*& Node<T>::getLeft() {
    return left;
}

template<class T>
void Node<T>::setLeft(Node<T>* left) {
    this->left = left;
}

template<class T>
Node<T>*& Node<T>::getRight() {
    return right;
}

template<class T>
void Node<T>::setRight(Node<T>* right) {
    this->right = right;
}