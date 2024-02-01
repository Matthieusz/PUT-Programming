#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <typename T>
class AVLTree {
private:
    AVLNode<T>* root;

    AVLNode<T>* rotateRight(AVLNode<T>* node) {
        AVLNode<T>* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        updateBalanceFactor(node);
        updateBalanceFactor(newRoot);
        return newRoot;
    }

    AVLNode<T>* rotateLeft(AVLNode<T>* node) {
        AVLNode<T>* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        updateBalanceFactor(node);
        updateBalanceFactor(newRoot);
        return newRoot;
    }

    AVLNode<T>* balance(AVLNode<T>* node) {
        updateBalanceFactor(node);

        if (node->balanceFactor > 1) {
            if (node->right->balanceFactor < 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        if (node->balanceFactor < -1) {
            if (node->left->balanceFactor > 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }

        return node;
    }

    void updateBalanceFactor(AVLNode<T>* node) {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->balanceFactor = rightHeight - leftHeight;
    }

    int getHeight(AVLNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    AVLNode<T>* insert(AVLNode<T>* node, T value) {
        if (node == nullptr) {
            return new AVLNode<T>(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return balance(node);
    }

    AVLNode<T>* remove(AVLNode<T>* node, T value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                AVLNode<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                AVLNode<T>* temp = node->left;
                delete node;
                return temp;
            } else {
                AVLNode<T>* minNode = findMin(node->right);
                node->data = minNode->data;
                node->right = remove(node->right, minNode->data);
            }
        }

        return balance(node);
    }

    AVLNode<T>* findMin(AVLNode<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    bool search(AVLNode<T>* node, T value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    void printPreorder(AVLNode<T>* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            printPreorder(node->left);
            printPreorder(node->right);
        }
    }

    void printInorder(AVLNode<T>* node) {
        if (node != nullptr) {
            printInorder(node->left);
            cout << node->data << " ";
            printInorder(node->right);
        }
    }

    void printPostorder(AVLNode<T>* node) {
        if (node != nullptr) {
            printPostorder(node->left);
            printPostorder(node->right);
            cout << node->data << " ";
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(T value) {
        root = insert(root, value);
    }

    void remove(T value) {
        root = remove(root, value);
    }

    bool search(T value) {
        return search(root, value);
    }

    void printTree(int order) {
        switch (order) {
            case 0:
                printPreorder(root);
                break;
            case 1:
                printInorder(root);
                break;
            case 2:
                printPostorder(root);
                break;
            default:
                cout << "Invalid input." << endl;
        }
    }
};