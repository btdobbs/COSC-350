class Element{
public:
    int key;
    int value;
};

class Node{
public:
    ~Node();
private:
    Element _element = {0,0};
    Node *_parent = nullptr;
    Node *_left = nullptr;
    Node *_right = nullptr;

    friend class LinkedBinarySearchTree;
    friend class Position;
};

class Position{
private:
    Node *_node;
public:
    Position();
    explicit Position(Node *node);
    int get_key() const;
    int get_value() const;
    Position left() const;
    Position right() const;
    Position parent();
    bool is_root();
    bool is_external() const;

    friend class LinkedBinarySearchTree;
};