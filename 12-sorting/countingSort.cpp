#include <cstdlib>
#include <iostream>

using namespace std;

void initArray(char a[], int arraySize)
{
  srand((unsigned) time(NULL));
  int max = 122;
  int min = 65;
  int range = max - min + 1;
  for(int i = 0; i < arraySize; i++)
  {
    a[i] = (char)(rand() % range + min);
  }
}

void printArray(const char a[], int arraySize)
{
  for(int i = 0; i < arraySize; i++)
  {
    cout << a[i];
    if (i < arraySize-1)
      cout << ", ";
  }
  cout << "\n";
}

void printArray(const short a[], int arraySize)
{
  bool firstComma = false;
  for(int i = 0; i < arraySize; i++)
  {
    for (int j = 0; j < a[i]; j++)
    {
      if (firstComma)
        cout << ", ";
      else
        firstComma = true;
      cout << (char)i;
    }
  }
  cout << "\n";
}

int countingSort(char a[], int arraySize, short countSort[])
{
  int steps = 0;
  for (int i = 0; i < arraySize; i++)
  {
    steps++;
    countSort[(short)a[i]]++;
  }
  return steps;
}

int main()
{
  int charCount = 0;
  cout << "Enter a positivie number of characters to generate and sort less than "
       << numeric_limits<short>::max()+1 << ".\n";
  cin >> charCount;
  if (charCount <= 0 || charCount > numeric_limits<short>::max())
    cout << "Please enter a positive number less than "
         << numeric_limits<short>::max()+1 << "\n";
  else
  {
    int steps = 0;
    char characters[charCount];
    initArray(characters, charCount);
    printArray(characters, charCount);
    short sortedCharacters[256] = {};
    steps = countingSort(characters, charCount, sortedCharacters);
    cout << "The sort took " << steps << " steps.\n";
    printArray(sortedCharacters, 256);
  }
  return 0;
}
