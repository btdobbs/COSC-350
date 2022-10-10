#include <iostream>
using namespace std;

//Thanks to Dr. Garrett for the content of this disccusion
//https://replit.com/@agarrett/COSC35005Oct2022?v=1

/*
1. Layout of memory (stack/heap)
2. Examples to show memory addresses
3. Array indexing arithmetic
4. 2D arrays in memory
5. Structures in memory
6. Dynamic memory
*/

int main() {
  int m = 5;
  int* p = new int;
  *p = 42;
  
  cout << &m << endl;
  cout << p << endl;
  cout << &p << endl;
  cout << *p << endl;

  delete p;
  cout << p << endl;
  
  /*
  int arr[5];
  for (int i = 0; i < 5; i++) {
    arr[i] = i + 1;
  }
  cout << arr << endl;
  cout << &arr[0] << endl;
  cout << &arr[1] << endl;
  */
  /*
  int x = 7;
  int y = 5;
  int z = 2;
  cout << &x << endl;
  cout << &y << endl;
  cout << &z << endl;
  {
    int w = 42;
    cout << &w << endl;
  }
  int a;
  cout << &a << endl;
  cout << a << endl;
  */

  
  return 0;
}
