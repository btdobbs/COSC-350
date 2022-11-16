#include "PositionList.h"
#include <iostream>

//binary tree
//ordered tree with at most two children
//each node has a left and a right child with left preceding right
//left and right child of internal node is considered left and right subtree
//proper or full binary tree consists of nodes with zero or two children
//Examples: decision trees, arithmetic-expression tree
//Properties:
// depth is zero (root) to n, max nodes at each level is 2^depth
// height log(n+1)-1 <= h <= (n-1)/2
// proper has external nodes equal to one plus internal nodes
// BST (binary search tree)
//  proper binary tree based on an order relation
//  keys to the left are greater than root
//  keys to the right are less than root
//  external nodes don't store values
//  searching for values: best case (balanced) - log_n, worst case n
class LinkedBinarySearchTree{
private:
    Node *_root = nullptr;
    int _size = 0;
    void visit(const Position &position);
public:
    explicit LinkedBinarySearchTree(int root_key, int root_value);
    ~LinkedBinarySearchTree();
    int size() const;
    bool empty() const;
    Position root();
    PositionList positions() const;
    void insert(int key, int value, const Position &position);
    //change node at position from external to internal
    void expand_external(const Position &position);
    //remove node at position and its parent and link grandparent to sibling
    Position remove_above_external(const Position &position);
    void preorder(const Position &position);
    void postorder(const Position &position);
    void inorder(const Position &position);
    int get_value(int key, const Position &position);
};