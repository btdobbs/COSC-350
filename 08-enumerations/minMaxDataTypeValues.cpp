#include <iostream>
using namespace std;
int main()
{
  cout << "max bool = " << numeric_limits<bool>::max() << "\n";
  cout << "min bool = " << numeric_limits<bool>::min() << "\n";
  cout << "bool bytes = " << sizeof(bool) << "\n";
  cout << "max char = " << int(numeric_limits<char>::max()) << "\n";
  cout << "min char = " << int(numeric_limits<char>::min()) << "\n";
  cout << "char bytes = " << sizeof(char) << "\n";
  cout << "max short = " << numeric_limits<short>::max() << "\n";
  cout << "min short = " << numeric_limits<short>::min() << "\n";
  cout << "short bytes = " << sizeof(short) << "\n";
  cout << "max int = " << numeric_limits<int>::max() << "\n";
  cout << "min int = " << numeric_limits<int>::min() << "\n";
  cout << "int bytes = " << sizeof(int) << "\n";
  cout << "max long = " << numeric_limits<long>::max() << "\n";
  cout << "min long = " << numeric_limits<long>::min() << "\n";
  cout << "long bytes = " << sizeof(long) << "\n";
  cout << "max float = " << numeric_limits<float>::max() << "\n";
  cout << "min float = " << numeric_limits<float>::min() << "\n";
  cout << "float bytes = " << sizeof(float) << "\n";
  cout << "max double = " << numeric_limits<double>::max() << "\n";
  cout << "min double = " << numeric_limits<double>::min() << "\n";
  cout << "double bytes = " << sizeof(double) << "\n";
  return 0;
}
