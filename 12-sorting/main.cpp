#include <iostream>

using namespace std;

void printArray(const int a[], int arraySize) {
    cout << "[";
    for (int i = 0; i < arraySize-1; i++) {
        cout << a[i] << ",";
    }
    if (arraySize != 0)
        cout << a[arraySize-1];
    cout << "]" << endl;
}

void insertionSort(int a[], int arraySize) {
  bool print = false;
  // iterate though each item to determine if a shift is needed
  for (int i = 1; i < arraySize; i++) {
    int cur = a[i];
    int j = i - 1;
    cout << "Before while\n";
    cout << "i = " << i << ";j = " << j << "\n";
    // check if a shift is needed
    while ((j >= 0) && (a[j] > cur)) {
      print = true;
      cout << "In while\n";
      cout << "i = " << i << ";j = " << j << "\n";
      a[j + 1] =
          a[j]; // shifting items to make space for the items that needs to move
      j--;
    }
    cout << "After while\n";
    cout << "i = " << i << ";j = " << j << "\n";
    a[j + 1] = cur; // items shifted and space made so item can move
    if (print) {
      print = false;
      printArray(a, arraySize);
    }
  }
}

int main() {
  int list[8] = {2, 3, 4, 1, 5, 8, 7, 6};
  printArray(list, 8);
  insertionSort(list, 8);
}
