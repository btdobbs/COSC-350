#include "PositionList.h"

void PositionList::put_position(int index, Position position) {
    _position[index] = position;
}

PositionList::PositionList(int size) {
    _size = size;
    _position = new Position[_size];
}

PositionList::~PositionList() {
    delete _position;
}

Position PositionList::get_position(int index) {
    return _position[index];
}
