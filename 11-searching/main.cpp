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

//return the index of first occurence of searchValue or -1 if searchValue is not found
int searchArray(int searchValue, const int a[], int arraySize)
{
  int foundIndex = -1;
  int steps = 0;
  for(int i = 0; i < arraySize; i++)
  {
    steps++;
    if (a[i] == searchValue)
    {
      foundIndex = i;
      break;
    }
  }
  cout << "[took " << steps << " step(s)] ";
  return foundIndex;
}

//return the index of first occurence of searchValue or -1 if searchValue is not found
//aSorted must be a sorted array (potential cost here)
int searchSortedArray(int searchValue, const int aSorted[], int arraySize)
{
  int min_index = 0;
  int mid_index = 0;
  int max_index = arraySize-1;
  int steps = 0;
  int foundIndex = -1;
  while(true)
  {
    steps++;
    mid_index = (min_index + max_index)/2;
    if (aSorted[mid_index] == searchValue)
    {
      foundIndex = mid_index;
      break;
    }
    else if (min_index == max_index)
      break;
    else if (aSorted[mid_index] < searchValue)
      min_index = mid_index + 1;
    else
      max_index = mid_index - 1;
  }
  cout << "[took " << steps << " step(s)] ";
  return foundIndex;
}

int main() {
  int a[] = {4, 2, 7, 8, 5, 1};
  int arraySize = sizeof(a)/sizeof(a[0]);
  printArray(a, arraySize);
  cout << "The index of 4 is " << searchArray(4, a, arraySize) << "\n";
  cout << "The index of 5 is " << searchArray(5, a, arraySize) << "\n";
  cout << "The index of 2 is " << searchArray(2, a, arraySize) << "\n";
  cout << "The index of 9 is " << searchArray(9, a, arraySize) << "\n";

  int aSorted[] = {1, 2, 4, 5, 7, 8};
  arraySize = sizeof(aSorted)/sizeof(aSorted[0]);
  printArray(aSorted, arraySize);
  cout << "The index of 4 is " << searchSortedArray(4, aSorted, arraySize) << "\n";
  cout << "The index of 5 is " << searchSortedArray(5, aSorted, arraySize) << "\n";
  cout << "The index of 2 is " << searchSortedArray(2, aSorted, arraySize) << "\n";
  cout << "The index of 9 is " << searchSortedArray(9, aSorted, arraySize) << "\n";
}

