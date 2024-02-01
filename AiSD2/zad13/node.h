#pragma once
#include <iostream>

using namespace std;    

template <typename T>
class AVLNode {
public:
    AVLNode(T value) : data(value), left(nullptr), right(nullptr), balanceFactor(0) {}

    T data;
    AVLNode<T>* left;
    AVLNode<T>* right;
    int balanceFactor;
};