#include <iostream>
#include "ArrayQueue.h"
//#include "ListQueue.h"

using namespace std;

int main(){
    ArrayQueue queue;
    Element e;
    char option;
    do{
        cout << queue.to_string() << endl;
        cout << "Size = " << queue.size() << endl;
        cout << "Empty = " << queue.empty() << endl;
        cout << "Enter option: (d)equeue, (e)nqueue, e(x)it" << endl;
        cin >> option;
        switch (option) {
            case 'd':
                queue.dequeue();
                break;
            case 'e':
                queue.enqueue(e);
                break;
            case 'x':
                break;
            default:
                cout << option << " is not a valid option." << endl;
                break;
        }
    }while (option != 'x');
    return 0;
}
