#pragma once
#include "node.h"
#include <vector>

template<class T>
class Tree {
    public:
        Tree();
        ~Tree();
        void add(T data);
        void remove(T data);
        int longestPath();
        int shortestPath();
        void printPreOrder();
        void printInOrder();
        void printPostOrder();
    private:
        Node<T>* root;
        void add(T data, Node<T>*& node);
        void remove(T data, Node<T>*& node);
        int longestPath(Node<T>* node);
        int shortestPath(Node<T>* node);
        void printPreOrder(Node<T>* node);
        void printInOrder(Node<T>* node);
        void printPostOrder(Node<T>* node);
};

template<class T>
Tree<T>::Tree() : root(nullptr) {}

template<class T>
Tree<T>::~Tree() {
    delete root;
}

template<class T>
void Tree<T>::add(T data) {
    add(data, root);
}

template<class T>
void Tree<T>::remove(T data) {
    remove(data, root);
}

template<class T>
int Tree<T>::longestPath() {
    return longestPath(root);
}

template<class T>
int Tree<T>::shortestPath() {
    return shortestPath(root);
}

template<class T>
void Tree<T>::printPreOrder() {
    printPreOrder(root);
}

template<class T>
void Tree<T>::printInOrder() {
    printInOrder(root);
}

template<class T>
void Tree<T>::printPostOrder() {
    printPostOrder(root);
}

template<class T>
void Tree<T>::add(T data, Node<T>*& node) {
    if (node == nullptr) {
        node = new Node<T>(data);
    } else if (data >= node->getData()) {
        add(data, node->getLeft());
    } else {
        add(data, node->getRight());
    }
}

template<class T>
void Tree<T>::remove(T data, Node<T>*& node) {
    if (node != nullptr) {
        if (data < node->getData()) {
            remove(data, node->getRight());
        } else if (data > node->getData()) {
            remove(data, node->getLeft());
        } else {
            if (node->getLeft() != nullptr && node->getRight() != nullptr) {
                Node<T>* temp = node->getLeft();
                while (temp->getRight() != nullptr) {
                    temp = temp->getRight();
                }
                node->setData(temp->getData());
                remove(node->getData(), node->getLeft());
            } else {
                Node<T>* temp = node;
                node = (node->getLeft() != nullptr) ? node->getLeft() : node->getRight();
                delete temp;
            }
        }
    }
}

template<class T>
int Tree<T>::longestPath(Node<T>* node) {
    if (node == nullptr) {
        return 0;
    } else {
        return 1 + max(longestPath(node->getLeft()), longestPath(node->getRight()));
    }
}

template<class T>
int Tree<T>::shortestPath(Node<T>* node) {
    if (node == nullptr) {
        return 0;
    } else {
        if (node->getLeft() == nullptr && node->getRight() == nullptr) {
            return 0;
        }
        if (node->getLeft() == nullptr) {
            return 1 + shortestPath(node->getRight());
        }
        if (node->getRight() == nullptr) {
            return 1 + shortestPath(node->getLeft());
        }   
        return 1 + min(shortestPath(node->getLeft()), shortestPath(node->getRight()));
    }
}

template<class T>
void Tree<T>::printPreOrder(Node<T>* node) {
    if (node != nullptr) {
        cout << node->getData() << " ";
        printPreOrder(node->getLeft());
        printPreOrder(node->getRight());
    }
}

template<class T>
void Tree<T>::printInOrder(Node<T>* node) {
    if (node != nullptr) {
        printInOrder(node->getLeft());
        cout << node->getData() << " ";
        printInOrder(node->getRight());
    }
}

template<class T>
void Tree<T>::printPostOrder(Node<T>* node) {
    if (node != nullptr) {
        printPostOrder(node->getLeft());
        printPostOrder(node->getRight());
        cout << node->getData() << " ";
    }
}