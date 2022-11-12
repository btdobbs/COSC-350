//several more ways to define a node
struct Node1{
    int key;
    Node1 *next;
};

class Node2_1{
public:
    int key;
    Node2_1 *next;
};

class Node2_2{
private:
    int key;
    Node2_2 *next;
public:
    inline int get_key() const {return key;}
    inline void set_key(int new_key) {key = new_key;}
    inline Node2_2 *get_next() {return next;}
    inline void set_next(Node2_2 *new_next) {next = new_next;}
};

class LinkedList1{
private:
    class Node3{
    public:
        int key;
        Node3 *next;
    };
};