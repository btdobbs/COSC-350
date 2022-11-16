#include "LinkedBinarySearchTree.h"

int LinkedBinarySearchTree::size() const {
    return _size;
}

bool LinkedBinarySearchTree::empty() const {
    return (_size == 0);
}

Position LinkedBinarySearchTree::root() {
    return Position(_root);
}

PositionList LinkedBinarySearchTree::positions() const {
    PositionList position_list(_size);
    //TODO: implement
    return position_list;
}

LinkedBinarySearchTree::~LinkedBinarySearchTree() {
    delete _root;
}

LinkedBinarySearchTree::LinkedBinarySearchTree(int root_key, int root_value) {
    _root = new Node();
    _root->_element.key = root_key;
    _root->_element.value = root_value;
    _size++;
    expand_external(root());
}

void LinkedBinarySearchTree::expand_external(const Position &position) {
    Node *node = position._node;
    node->_left = new Node();
    node->_left->_parent = node;
    node->_right = new Node();
    node->_right->_parent = node;
    _size+=2;
}

Position LinkedBinarySearchTree::remove_above_external(const Position &position) {
    Node *node = position._node;
    Node *parent_node = node->_parent;
    Node *sibling_node;
    if (node == parent_node->_left)
        sibling_node = parent_node->_right;
    else
        sibling_node = parent_node->_left;
    if (node == _root){
        _root = sibling_node;
        sibling_node->_parent = nullptr;
    }
    else{
        Node *grandparent_node = parent_node->_parent;
        if (parent_node == grandparent_node->_left)
            grandparent_node->_left = sibling_node;
        else
            grandparent_node->_right = sibling_node;
        sibling_node->_parent = grandparent_node;
    }
    delete node;
    delete parent_node;
    _size -= 2;
    return Position(sibling_node);
}

void LinkedBinarySearchTree::visit(const Position &position){
    if (!position.is_external())
        std::cout << position.get_key() << "(" << position.get_value() << ")" << ", ";
}

void LinkedBinarySearchTree::preorder(const Position &position) {
    visit(position);
    if (!position.is_external()) {
        preorder(position.left());
        preorder(position.right());
    }
}

void LinkedBinarySearchTree::postorder(const Position &position) {
    if (!position.is_external()) {
        postorder(position.left());
        postorder(position.right());
    }
    visit(position);
}

void LinkedBinarySearchTree::inorder(const Position &position) {
    if (!position.is_external())
        inorder(position.left());
    visit(position);
    if (!position.is_external())
        inorder(position.right());
}

void LinkedBinarySearchTree::insert(int key, int value, const Position &position) {
    if (position.is_external()){
        position._node->_element.key = key;
        position._node->_element.value = value;
        expand_external(position);
        return;
    }
    if (key < position.get_key())
        insert(key, value, position.left());
    else
        insert(key, value, position.right());
}

int LinkedBinarySearchTree::get_value(int key, const Position &position) {
    if (position.is_external())
        return -1;
    if (position.get_key() == key)
        return position.get_value();
    if (key < position.get_key())
        return get_value(key, position.left());
    else
        return get_value(key, position.right());
}
