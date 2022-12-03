#include <iostream>
#include "CharacterList.h"

using namespace std;

void test_add_back(){
    CharacterList character_list;
    character_list.add_front('a');
    character_list.add_back('b');
    character_list.add_front('c');
    character_list.add_back('d');
    if (character_list.to_string() == "cabd")
        cout << "add_back pass" << endl;
    else
        cout << "add_back fail" << endl;
}

void test_add_after(){
    CharacterList character_list;
    character_list.add_front('a');
    character_list.add_after('b','a');
    character_list.add_front('c');
    character_list.add_after('a','d');
    if (character_list.to_string() == "cab")
        cout << "add_after pass" << endl;
    else
        cout << "add_after fail" << endl;
}

void test_remove_back(){
    CharacterList character_list;
    character_list.add_front('a');
    character_list.add_front('b');
    character_list.remove_back();
    character_list.add_front('a');
    character_list.remove_back();
    if (character_list.to_string() == "a")
        cout << "remove_back pass" << endl;
    else
        cout << "remove_back fail" << endl;
}

void test_remove(){
    CharacterList character_list;
    character_list.add_front('a');
    character_list.add_front('b');
    character_list.add_front('a');
    character_list.remove('a');
    if (character_list.to_string() == "ba")
        cout << "remove pass" << endl;
    else
        cout << "remove fail" << endl;
}

void test_size() {
    CharacterList character_list;
    character_list.add_front('a');
    character_list.add_front('b');
    character_list.add_front('a');
    if (character_list.size() == 3)
        cout << "size pass" << endl;
    else {
        cout << "size fail" << character_list.to_string() << character_list.size() << endl;
    }
}

void test_back(){
    CharacterList character_list;
    character_list.add_front('a');
    character_list.add_front('b');
    character_list.add_front('a');
    if (character_list.back() == 'a')
        cout << "back pass" << endl;
    else
        cout << "back fail" << endl;
}

int main() {
    test_add_back();
    test_add_after();
    test_remove_back();
    test_remove();
    test_size();
    test_back();
    return 0;
}
