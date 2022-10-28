#include <iostream>

using namespace std;
// recap correct pointer usage
// recap pointers and references
// risk 1 - memory leak
// risk 2 - segmentation fault
// dynamic arrays

void doCorrectUsage()
{
    // a pointer to integer
    int *aPointerVariable;

    //Use new operator to Allocate memory for aPointerVariable
    aPointerVariable = new int;

    //A * is necessary to assign value to aPointerVariable (de-referencing)
    *aPointerVariable = 5;

    //Prints the value of int (de-referencing)
    cout << "\n\taPointerVariable value=" << *aPointerVariable;

    //Prints memory location, where int is stored
    cout << "\n\taPointerVariable stored at address=" << aPointerVariable << "\n";

    //Prints memory location where memory location of aPointerVariable is stored
    cout << "\n\tint stored at address=" << &aPointerVariable << "\n";

    //Deallocate memory reserved for the int (to avoid memory leaks)
    delete aPointerVariable;
}

void doPointersAndVariableReference()
{
    int *aPointerToReferenceVariable;

    int anIntReference = 10;

    cout << "\n\tanIntReference = " << anIntReference << "\n";

    cout << "\n\tMemory address of anIntReference = " << &anIntReference << "\n";

    aPointerToReferenceVariable = &anIntReference;

    cout << "\n\taPointerToReferenceVariable after assigment to memory address of anIntReference =" << aPointerToReferenceVariable << "\n";

    cout << "\n\taPointerToReferenceVariable de-referenced = " << *aPointerToReferenceVariable << "\n";
}

void doIncorrectUsageWithMemoryLeak()
{
  //don't do this!  Bad practice
    int *aPointerVariable;
    aPointerVariable = new int;
    //we didn't use delete so memory is not recovered (i.e. The OS will think the memory is being used)
}

void doIncorrectUsageWithSegmentationFault() {
    //don't do this!  Bad practice
    int *ptr;
    ptr = new int;
    while(true) {
        //The following will throw a segmentation fault
        //when we run out of the program's address space.
        *(ptr++) = 5;
    }
}

void printArray(const int a[], int arraySize) {
    cout << "[";
    for (int i = 0; i < arraySize-1; i++) {
        cout << a[i] << ",";
    }
    if (arraySize != 0)
        cout << a[arraySize-1];
    cout << "]" << endl;
}

void doDynamicArray()
{
    int arraySize = 10;
    int *dynamicArray = new int[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        dynamicArray[i] = i;
    }
    printArray(dynamicArray, arraySize);
    //Get in the habit of using [] with array delete.  Why on Monday.
    delete[] dynamicArray;
}

int main() {
    //doCorrectUsage();
    //doPointersAndVariableReference();
    //doIncorrectUsageWithMemoryLeak();
    //doIncorrectUsageWithSegmentationFault();
    doDynamicArray();
}
