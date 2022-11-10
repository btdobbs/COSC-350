#include "Stack.h"

class HundredArrayStack : Stack{
private:
    int _size = 0;
    Element a[100]={};
public:
    void push(Element e) override {
        a[_size] = e;
        _size++;
    }

    void pop() override {
        _size--;
    }

    Element top() override {
        return a[_size-1];
    }

    int size() override {
        return _size;
    }

    bool empty() override {
        return _size == 0;
    }

};