#include "PriorityQueue.h"
#include <iostream>
#include <random>

using namespace std;

int main() {
    int min = 1;
    int max = 100;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    uniform_int_distribution<int> distribution(min,max);
    PriorityQueue priority_queue;
    int n;
    for(int i = 0; i < 10; i++){
        n = distribution(generator);
        cout << "add " << n << endl;
        priority_queue.insert(n);
    }
    cout << endl;
    while (!priority_queue.empty()){
        n = priority_queue.min();
        cout << n << endl;
        priority_queue.remove_min();
    }
    return 0;
}
