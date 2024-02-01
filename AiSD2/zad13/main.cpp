#include <iostream>
#include "tree.h"
#include "node.h"

using namespace std;

int main() {
    AVLTree<int> avlTree;

    int K, L, M;

    cin >> K;

    for (int i = 0; i < K; ++i) {
        int element;
        cin >> element;
        avlTree.insert(element);
    }
    
    cin >> L;
    avlTree.remove(L);

    cin >> M;
    avlTree.printTree(M);

    return 0;
}
