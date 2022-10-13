#include <iostream>

using namespace std;

void printTypeInfo(char aTypeChar)
{
  string typeName;
  string maxValue;
  string minValue;
  string byteValue;

  switch(aTypeChar)
  {
    case 'b':
      typeName = "bool";
      maxValue = to_string(numeric_limits<bool>::max());
      minValue = to_string(numeric_limits<bool>::min());
      byteValue = to_string(sizeof(bool));
      break;
    case 'c':
      typeName = "char";
      maxValue = to_string(numeric_limits<char>::max());
      minValue = to_string(numeric_limits<char>::min());
      byteValue = to_string(sizeof(char));
      break;
    case 's':
      typeName = "short";
      maxValue = to_string(numeric_limits<short>::max());
      minValue = to_string(numeric_limits<short>::min());
      byteValue = to_string(sizeof(short));
      break;
    case 'i':
      typeName = "int";
      maxValue = to_string(numeric_limits<int>::max());
      minValue = to_string(numeric_limits<int>::min());
      byteValue = to_string(sizeof(int));
      break;
    case 'l':
      typeName = "long";
      maxValue = to_string(numeric_limits<long>::max());
      minValue = to_string(numeric_limits<long>::min());
      byteValue = to_string(sizeof(long));
      break;
    case 'f':
      typeName = "float";
      maxValue = to_string(numeric_limits<float>::max());
      minValue = to_string(numeric_limits<float>::min());
      byteValue = to_string(sizeof(float));
      break;
    case 'd':
      typeName = "double";
      maxValue = to_string(numeric_limits<double>::max());
      minValue = to_string(numeric_limits<double>::min());
      byteValue = to_string(sizeof(double));
      break;
    default:
      cout << "Invalid type specified:" << aTypeChar << "\n";
      return;
  }
  cout << "max " << typeName << " = " << maxValue << "\n";
  cout << "min " << typeName << " = " << minValue << "\n";
  cout << typeName << " bytes = " << byteValue << "\n\n";
}

int main()
{
  string types = "bcsilfd";
  for (int i = 0; i <= 6; i++)
  {
    printTypeInfo(types[i]);
  }
  return 0;
}
