#include <iostream>

using namespace std;

class Node{
private:
    int key;
    Node *next;

    friend class LinkedList;
};

class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    int front() const;
    void add_front(int key);
    void remove_front();
    bool exists(int key);
    void print();
private:
    Node *head;
};

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    while(!empty()) remove_front();
}

bool LinkedList::empty() const {
    return head == nullptr;
}

int LinkedList::front() const {
    return head->key;
}

void LinkedList::add_front(const int key) {
    Node *n = new Node;
    n->key = key;
    n->next = head;
    head = n;
}

void LinkedList::remove_front() {
    if (empty()) return;
    Node *temp = head;
    head = temp->next;
    delete temp;
}

bool LinkedList::exists(int key) {
    Node *temp = head;
    while(temp != nullptr) {
        if (temp->key == key)
            return true;
        temp = temp->next;
    }
    return false;
}

void LinkedList::print() {
    cout << "<";
    Node *temp = head;
    while(temp != nullptr) {
        cout << temp->key;
        if (temp->next != nullptr)
            cout << ", ";
        temp = temp->next;
    }
    cout << ">" << endl;
}

int main() {
    LinkedList linked_list;
    //cout << linked_list.front() << endl; //note this will produce an error for an empty list
    linked_list.remove_front();
    linked_list.print();
    linked_list.add_front(1);
    linked_list.add_front(2);
    linked_list.add_front(3);
    linked_list.add_front(4);
    linked_list.add_front(5);
    linked_list.print();
    linked_list.remove_front();
    cout << linked_list.front() << endl;
    linked_list.print();
    cout << linked_list.exists(3) << endl;
    cout << linked_list.exists(9) << endl;
    return 0;
}
