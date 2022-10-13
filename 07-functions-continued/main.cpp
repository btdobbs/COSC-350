#include <iostream>

using namespace std;

void printValues(int& a, const int& b, int c, int d[], int arraySize)
{
  cout << "m = " << a << "\n";
  cout << "n = " << b << "\n";
  cout << "o = " << c << "\n";
  for(int i = 0; i < arraySize; i++)
  {
    cout << "p[" << i << "] = " << d[i] << "\n";
  }
}

void changeValues(int& a, const int& b, int c, int d[], const int e[], int arraySize)
{
  a++;
  //b++; not allowed due to const
  c++;
  for(int i = 0; i < arraySize; i++)
  {
    d[i]++;
  }
  // below not allowed due to const
  // for(int i = 0; i < arraySize; i++)
  // {
  //   e[i]++;
  // }
}

int main()
{
  int m = 0;
  int n = 0;
  int o = 0;
  int p[] = {0,0,0,0};
  int arraySize = sizeof(p)/sizeof(p[0]);
  cout << "Before\n";
  printValues(m,n,o,p,arraySize);
  changeValues(m,n,o,p,p,arraySize);
  cout << "After\n";
  printValues(m,n,o,p,arraySize);
  return 0;
}
