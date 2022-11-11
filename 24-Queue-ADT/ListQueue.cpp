#include "ListQueue.h"

ListQueue::~ListQueue(){
    while(!empty())
        dequeue();
}

void ListQueue::enqueue(Element e) {
    Node *n = new Node;
    n->element = e;
    n->next = head;
    if (head != nullptr)
        head->previous = n;
    head = n;
    _size++;
    if (_size == 1)
        tail = n;
}

void ListQueue::dequeue() {
    if (empty()) return;
    Node *temp = tail;
    tail = temp->previous;
    if (temp-> previous == nullptr)
        head = nullptr;
    else
        temp->previous->next = nullptr;
    delete temp;
    _size--;
}

Element ListQueue::front() {
    return tail->element;
}

int ListQueue::size() {
    return _size;
}

bool ListQueue::empty() {
    return _size == 0;
}

string ListQueue::to_string() const{
    string s;
    Node *temp = head;
    while(temp != nullptr) {
        if (temp == tail)
            s+= "-]";
        else
            s+= "-";
        temp = temp->next;
    }
    return s;
}