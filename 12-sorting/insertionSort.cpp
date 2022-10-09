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

int insertionSort(char a[], int arraySize)
{
    int steps = 0;
    for (int i = 1; i < arraySize; i++)
    {
        char cur = a[i];
        int j = i-1;
        while (j >= 0)
        {
            steps++;
            if (a[j] <= cur) break; //took check out of while so steps can be properly counted
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = cur;
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
        steps = insertionSort(characters, charCount);
        cout << "The sort took " << steps << " steps.\n";
        printArray(characters, charCount);
    }
    return 0;
}
