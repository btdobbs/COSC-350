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
    Node *temp = head;
    while(temp != nullptr) {
        if (temp->next == nullptr) {
            return temp->key;
        }
        temp = temp->next;
    }
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
    Node *temp = head;
    while(temp != nullptr) {
        if (temp->key == search_key) {
            Node *n = new Node;
            n->key = key;
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp = temp->next;
    }
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
    Node *temp = head;
    Node *prev = nullptr;
    while(temp != nullptr) {
        if (temp->key == key) {
            if (prev == nullptr)
                head = temp->next;
            else
                prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
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
    if (empty()) {
        add_front(key);
        return;
    }
    Node *temp = head;
    while(temp != nullptr) {
        if (temp->next == nullptr) {
            Node *n = new Node;
            n->key = key;
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp = temp->next;
    }
}

//removes key from the back of the list
void CharacterList::remove_back() {
    Node *temp = head;
    Node *prev = nullptr;
    while(temp != nullptr) {
        if (temp->next == nullptr) {
            if (prev == nullptr)
                head = nullptr;
            else
                prev->next = nullptr;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

int CharacterList::size() {
    Node *temp = head;
    int count = 0;
    while(temp != nullptr) {
        temp = temp->next;
        count++;
    }
    return count;
}
