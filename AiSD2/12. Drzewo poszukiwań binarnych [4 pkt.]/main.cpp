#include <iostream>
#include <vector>
#include "node.h"
#include "tree.h"

using namespace std;

int main() {
    Tree<double> tree;

    double value;
    double prevalue;
    int K, M;
    double L;

    cin >> K;
    for(int i = 0; i < K; i++) {
        cin >> value;
        tree.add(value);
    }

    cin >> L;
    for(int i = 0; i < L; i++) {
        cin >> value;
        tree.remove(value);
    }

    cin >> M;
    switch (M)
    {
    case 0:
        tree.printPreOrder();
        cout << tree.longestPath() - 1 << " ";
        cout << tree.shortestPath();
        break;
    case 1:
        tree.printInOrder();
        cout << tree.longestPath() - 1 << " ";
        cout << tree.shortestPath();
        break;
    case 2:
        tree.printPostOrder();
        cout << tree.longestPath() - 1 << " ";
        cout << tree.shortestPath();
        break;
    default:
        cout << "Invalid input";
        break;
    }

    return 0;
}