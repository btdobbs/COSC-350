#include "Element.h"
//LIFO (last in first out)
//cafeteria plates, pez, web, undo
//use virtual keyword to behave more like an interface
class Stack{
public:
    void push(Element e);  // add element to top of stack
    void pop(); // remove element from top of stack (error if empty)
    Element top(); // reference element on top of stack (error if empty)
    int size(); // size of stack
    bool empty(); //true if stack is empty
};
