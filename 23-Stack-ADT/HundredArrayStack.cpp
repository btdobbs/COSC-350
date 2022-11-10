#include "HundredArrayStack.h"

void HundredArrayStack::push(Element e) {
a[_size] = e;
_size++;
}

void HundredArrayStack::pop() {
_size--;
}

Element HundredArrayStack::top() {
return a[_size-1];
}

int HundredArrayStack::size() {
return _size;
}

bool HundredArrayStack::empty() {
return _size == 0;
}
