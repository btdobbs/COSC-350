#include <iostream>
#include <limits>

template <class T>
void printTypeInfo(std::string aTypeName)
{
  std::cout << "max " << aTypeName << " = " << std::numeric_limits<T>::max() << "\n";
  std::cout << "min " << aTypeName << " = " << std::numeric_limits<T>::min() << "\n";
  std::cout << aTypeName << " bytes = " << sizeof(T) << "\n\n"; //Note: typeid(T).name() does not return a proper name
}

int main()
{
  printTypeInfo<bool>("bool");
  printTypeInfo<char>("char");
  printTypeInfo<short>("short");
  printTypeInfo<int>("int");
  printTypeInfo<long>("long");
  printTypeInfo<float>("float");
  printTypeInfo<double>("double");
  return 0;
}
