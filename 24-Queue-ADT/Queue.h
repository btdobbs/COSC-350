#include "Element.h"
//FIFO (first in first out)
//waiting line, ticket number,
class Queue{
public:
    //virtual ~Queue() = 0;
    virtual void enqueue(Element e) = 0;   // add element to queue
    virtual void dequeue() = 0;            // remove element from front of queue (error if empty)
    virtual Element front() = 0;           // reference element from front of queue (error if empty)
    virtual int size() = 0;                // size of queue
    virtual bool empty() = 0;              //true if queue is empty
};
