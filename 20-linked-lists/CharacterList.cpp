#include "CharacterList.h"

using namespace std;

CharacterList::~CharacterList() {
    while(!empty())
        remove_front();
}

bool CharacterList::empty() {
    return head == nullptr;
}

//returns key from front of list
char CharacterList::front() {
    if (empty())
        return '\0';
    return head->key;
}

//returns key from back of list
char CharacterList::back() {
    //TODO: Add definition here
    return '\0';
}

//adds key to front of list
void CharacterList::add_front(char key) {
    Node *n = new Node;
    n->key = key;
    n->next = head;
    head = n;
}

//adds key in the list after search_key; if search_key isn't found, nothing is added
void CharacterList::add_after(char key, char search_key) {
    //TODO: Add definition here
}

//removes first item of the list
void CharacterList::remove_front() {
    if (empty()) return;
    Node *temp = head;
    head = temp->next;
    delete temp;
}

//removes first instance of key from the list
void CharacterList::remove(char key) {
    //TODO: Add definition here
}

//returns true if the key exists, false otherwise
bool CharacterList::exists(char key) {
    Node *temp = head;
    while(temp != nullptr) {
        if (temp->key == key)
            return true;
        temp = temp->next;
    }
    return false;
}

//returns a string representation of the list
string CharacterList::to_string() {
    string s;
    Node *temp = head;
    while(temp != nullptr) {
        s += string(1,temp->key);
        temp = temp->next;
    }
    return s;
}

//adds key to the back of the list
void CharacterList::add_back(char key) {
    //TODO: Add definition here
}

//removes key from the back of the list
void CharacterList::remove_back() {
    //TODO: Add definition here
}

int CharacterList::size() {
    int count = 0;
    //TODO: Add definition here
    return count;
}


