#include "Map.h"
#include <iostream>
#include <random>

using namespace std;

int main() {
    Map *map;
    Element key;
    Element value;
    Iterator position;
    position = map->put(key, value);
    position = map->find(key);
}
