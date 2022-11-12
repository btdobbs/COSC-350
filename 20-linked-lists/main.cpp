#include <iostream>
#include "CharacterList.h"

using namespace std;

void add_front(CharacterList &il){
    char target_char;
    cout << "Enter char to add: ";
    cin >> target_char;
    il.add_front(target_char);
}

void add_back(CharacterList &il){
    char target_char;
    cout << "Enter char to add: ";
    cin >> target_char;
    il.add_back(target_char);
}

void add(CharacterList &il){
    char target_char;
    char search_char;
    cout << "Enter char to add: ";
    cin >> target_char;
    cout << "Enter char to add after: ";
    cin >> search_char;
    il.add_after(target_char, search_char);
}

void remove(CharacterList &il){
    char target_char;
    cout << "Enter char to remove: ";
    cin >> target_char;
    il.remove(target_char);
}

int main() {
    CharacterList integer_list;
    char option;
    do{
        cout << integer_list.to_string() << endl;
        cout << "Size = " << integer_list.size() << endl;
        cout << "Empty = " << integer_list.empty() << endl;
        if (!integer_list.empty()){
            cout << "Front = " << integer_list.front() << endl;
            cout << "Back = " << integer_list.back() << endl;
        }
        cout << "Enter option:" << endl;
        cout << "(1) add front" << endl;
        cout << "(2) add back" << endl;
        cout << "(3) add" << endl;
        cout << "(4) remove front" << endl;
        cout << "(5) remove back" << endl;
        cout << "(6) remove" << endl;
        cout << "(7) exit" << endl;
        cout << "--> ";
        cin >> option;
        cout << endl;

        switch (option) {
            case '1':
                add_front(integer_list);
                break;
            case '2':
                add_back(integer_list);
                break;
            case '3':
                add(integer_list);
                break;
            case '4':
                integer_list.remove_front();
                break;
            case '5':
                integer_list.remove_back();
                break;
            case '6':
                remove(integer_list);
                break;
            case '7':
                break;
            default:
                cout << option << " is not a valid option." << endl;
                break;
        }
    }while (option != '7');
    return 0;
}
