#include "LinkedBinarySearchTree.h"
#include <cstdlib>

int get_random_number(int max){
    return rand() % max;
}

int get_hash(int value){
    return value % 13;
}

int main() {
    int max = 1000;
    srand((unsigned)time(NULL));
    int n = get_random_number(max);
    LinkedBinarySearchTree bst(n,get_hash(n));
    Position root = bst.root();
    for(int i = 0; i < 10; i++){
        n = get_random_number(max);
        bst.insert(n,get_hash(n),root);
    }
    bst.preorder(root);
    std::cout << std::endl;
    bst.postorder(root);
    std::cout << std::endl;
    bst.inorder(root);
    std::cout << std::endl;
    //n = get_random_number(max);
    int v = bst.get_value(n, root);
    std::cout << "value of " << n << " = " << v << std::endl;
    return 0;
}
