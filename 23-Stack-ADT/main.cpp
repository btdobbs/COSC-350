#include <iostream>
#include "Stack.h"
#include "Vector.h"

using namespace std;

void reverse(Vector v){
    HundredArrayStack stack;
    for (int i = 0; i < 10; i++) {
        stack.push(v.at(i));
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
    reverse(vector);
    //Other uses grouping match (i.e., (),{},[])
}
