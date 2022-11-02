#include <iostream>
#include "ADT.h"
#include "List.h"

int main() {
    //Well known ADT
    Number n1;
    Number n2;
    Number n3;
    n1 = n2 + n3;

    //List ADT
    List list;
    Position p = list.begin();
    while (p.has_next()){
        Element e = p.element();
        p = p.next();
        e.print();
    }
    return 0;
}
