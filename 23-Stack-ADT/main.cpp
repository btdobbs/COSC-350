#include <iostream>
#include "Stack.h"
#include "Vector.h"

using namespace std;

void reverse(Vector v){
    Stack stack;
    for (int i = 0; i < 10; i++) {
        Element e;
        stack.push(e);
    }
    for (int i = 0; i < 10; i++) {
        v.insert(i,stack.top());
        stack.pop();
    }
}

int main(){
    Vector vector;
    for (int i = 0; i < 10; i++) {
        Element e;
        vector.insert(i,e);
    }

    //Other uses grouping match (i.e., (),{},[])
}