#include "Sequence.h"
#include "Vector.h"
#include "OrderedList.h"
#include <cassert>

int main() {
    //Sequence ADT (index and position)
    Sequence sequence;
    const int index_1 = 5;
    Position position = sequence.at_index(index_1);
    const int index_2 = sequence.index_of(position);
    assert(index_1 == index_2);
    
    
    //Vector ADT
    Vector vector;
    const int max = 10;
    for(int i = 0; i < max; i++){
        Element element;
        vector.insert(i, element);
    }
    for(int i = 0; i < max; i++){
        Element element = vector.at(i);
        vector.erase(i);
        vector.set(i,element);
    }
    
    //Ordered List ADT
    OrderedList ordered_list;
    for(int i = 0; i < max; i++){
        Element element = vector.at(i);
        ordered_list.insert(element);
    }
}
