#include "Position.h"

class PositionList{
private:
    int _size;
    Position *_position;
    void put_position(int index, Position position);
public:
    explicit PositionList(int size);
    ~PositionList();
    Position get_position(int index);

    friend class BinaryTree;
};