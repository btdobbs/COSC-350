#include <iostream>

using namespace std;

// Note, arrays are always passed by reference hence the need for size.
// Also, array declared with const so new values can't be assigned.
void printArray(const int a[], int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    // const array paramenter prevents a[i] = <new value>
    cout << a[i];
    if (i < arraySize - 1)
      cout << ", ";
  }
  cout << "\n";
}

int main() {
  cout << "Array declared with specific values.\n";
  int a1[] = {4, 2, 7, 8, 5, 1};
  int arraySize = sizeof(a1) / sizeof(a1[0]);
  printArray(a1, arraySize);

  cout << "\nArray declared using variable for the size and no initialization "
          "of elements.\n";
  int a2[arraySize];
  printArray(a2, arraySize);

  cout << "\nArray declared using magic number for the size and initialization "
          "to zero.\n";
  int a3[6] = {};
  printArray(a3, arraySize);

  cout << "\nArray declared using magic number for the size and initialization "
          "of first element to one.\n";
  int a4[6] = {1};
  printArray(a4, arraySize);

  cout << "\nArray declared with specific values and print past the last "
          "value.\n";
  int a5[] = {4, 2, 7, 8, 5, 1};
  printArray(a5, arraySize + 1);

  cout << "\nIncrease array size (no pointers).\n";
  int a6[arraySize + 1];
  for (int i = 0; i < arraySize; i++) {
    a6[i] = a5[i];
  }
  a6[arraySize] = 9;
  printArray(a6, arraySize + 1);
}
