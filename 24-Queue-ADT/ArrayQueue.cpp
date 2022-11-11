#include "ArrayQueue.h"

ArrayQueue::ArrayQueue(){
    a = new Element[_max_size];
    _size = 0;
    reset_front();
}

ArrayQueue::~ArrayQueue(){
    delete[] a;
}

void ArrayQueue::grow(){
    int new_max = _max_size * 2;
    Element *temp;
    temp = new Element[new_max];
    int offset = new_max-_max_size;
    for (int i = 0; i < _max_size; i++)
        temp[offset+i] = a[i];

    delete a;
    a = temp;
    _max_size = new_max;
    reset_front();
}

void ArrayQueue::shift(){
    int b = _front;
    int index = _max_size;
    while(b > _back){
        a[index] = a[b];
        b--;
        index--;
    }
    reset_front();
}

void ArrayQueue::reset_front(){
    _front = _max_size-1;
    _back = _max_size-_size-1;
}

void ArrayQueue::enqueue(Element e) {
    if (_size == _max_size)
        grow();
    else if (_back < 0)
        shift();
    a[_back] = e;
    _size++;
    _back--;
}

void ArrayQueue::dequeue() {
    if (empty())
        return;
    _size--;
    _front--;
    if (empty())
        reset_front();
}

Element ArrayQueue::front() {
    return a[_front];
}

int ArrayQueue::size() {
    return _size;
}

bool ArrayQueue::empty() {
    return _size == 0;
}

string ArrayQueue::to_string() const{
    string s;
    for (int i = 0; i < _max_size; ++i) {
        if ((i == _front) && (i == _back))
            s+= "_]";
        else if (i == _front)
            s+= "-]";
        else if (i == _back)
            s+= "_";
        else if ((i > _back) && (i < _front))
            s+= "-";
        else
            s+= "_";
    }
    return s;
}