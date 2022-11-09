#include "Element.h"
//LIFO (last in first out)
//cafeteria plates, pez, web, undo
//use virtual keyword in C++ to behave more like a c#/java interface
//python - just class, javascript - prototype (nothing to enforce in these two)
class Stack{
public:
    virtual void push(Element e) = 0;  // add element to top of stack
    virtual void pop() = 0;            // remove element from top of stack (error if empty)
    virtual Element top() = 0;         // reference element on top of stack (error if empty)
    virtual int size() = 0;            // size of stack
    virtual bool empty() = 0;          //true if stack is empty
};
