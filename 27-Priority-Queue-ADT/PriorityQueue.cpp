#include "PriorityQueue.h"

int PriorityQueue::size() const {
    return _size;
}

int PriorityQueue::empty() const {
    return _size == 0;
}

int PriorityQueue::get_parent_index(int index){
    return index/2;
}

bool PriorityQueue::has_left_child(int index) const{
    return _size >= 2*index;
}

bool PriorityQueue::has_right_child(int index) const{
    return _size >= 2*index+1;
}

int PriorityQueue::get_left_child_index(int index) {
    return 2*index;
}

int PriorityQueue::get_right_child_index(int index) {
    return 2*index+1;
}

void PriorityQueue::insert(const int element) {
    int index;
    if (_size == 0)
        index = _root;
    else
        index = _size + 1;
    _a[index] = element;
    while (index != _root) {
        int parent_index = get_parent_index(index);
        if (_a[index] >= _a[parent_index])
            break;
        std::swap(_a[parent_index], _a[index]);
        index = parent_index;
    }
    _size++; //not adding grow code for demo
}

int PriorityQueue::min() const {
    return _a[_root];
}

void PriorityQueue::remove_min() {
    int index = _root;
    std::swap(_a[index], _a[_size]);
    _size--;
    while(has_left_child(index)){
        int min_child_index = get_left_child_index(index);
        if (has_right_child(index)){
            int index_right_child = get_right_child_index(index);
            if (_a[index_right_child] < _a[min_child_index])
                min_child_index = index_right_child;
        }
        if (_a[min_child_index] < _a[index]){
            std::swap(_a[index], _a[min_child_index]);
            index = min_child_index;
        }
        else
            break;
    }
}

PriorityQueue::~PriorityQueue() {
    delete[] _a;
}
