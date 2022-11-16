#include "Position.h"

Position::Position(Node *node) {
    _node = node;
}

int Position::get_key() const {
    return _node->_element.key;
}

int Position::get_value() const {
    return _node->_element.value;
}

Position Position::left() const {
    return Position(_node->_left);
}

Position Position::right() const {
    return Position(_node->_right);
}

Position Position::parent() {
    return Position(_node->_parent);
}

bool Position::is_root() {
    return _node->_parent == nullptr;
}

bool Position::is_external() const {
    return (_node->_left == nullptr) && (_node->_right == nullptr);
}

Position::Position() {
    _node = nullptr;
}

Node::~Node() {
    delete _left;
    delete _right;
}
