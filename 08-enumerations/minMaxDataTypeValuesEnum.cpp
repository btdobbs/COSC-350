#include <iostream>

using namespace std;

enum type { BOOL, CHAR, SHORT, INT, LONG, FLOAT, DOUBLE };

void printTypeInfo(type aType)
{
  string typeName;
  string maxValue;
  string minValue;
  string byteValue;

  switch(aType)
  {
    case BOOL:
      typeName = "bool";
      maxValue = to_string(numeric_limits<bool>::max());
      minValue = to_string(numeric_limits<bool>::min());
      byteValue = to_string(sizeof(bool));
      break;
    case CHAR:
      typeName = "char";
      maxValue = to_string(numeric_limits<char>::max());
      minValue = to_string(numeric_limits<char>::min());
      byteValue = to_string(sizeof(char));
      break;
    case SHORT:
      typeName = "short";
      maxValue = to_string(numeric_limits<short>::max());
      minValue = to_string(numeric_limits<short>::min());
      byteValue = to_string(sizeof(short));
      break;
    case INT:
      typeName = "int";
      maxValue = to_string(numeric_limits<int>::max());
      minValue = to_string(numeric_limits<int>::min());
      byteValue = to_string(sizeof(int));
      break;
    case LONG:
      typeName = "long";
      maxValue = to_string(numeric_limits<long>::max());
      minValue = to_string(numeric_limits<long>::min());
      byteValue = to_string(sizeof(long));
      break;
    case FLOAT:
      typeName = "float";
      maxValue = to_string(numeric_limits<float>::max());
      minValue = to_string(numeric_limits<float>::min());
      byteValue = to_string(sizeof(float));
      break;
    case DOUBLE:
      typeName = "double";
      maxValue = to_string(numeric_limits<double>::max());
      minValue = to_string(numeric_limits<double>::min());
      byteValue = to_string(sizeof(double));
      break;
    default:
      cout << "Invalid type specified:" << aType << "\n";
      return;
  }
  cout << "max " << typeName << " = " << maxValue << "\n";
  cout << "min " << typeName << " = " << minValue << "\n";
  cout << typeName << " bytes = " << byteValue << "\n\n";
}

int main()
{
  for (int i = 0; i < 6; i++)
  {
    printTypeInfo((type)i);
  }
  return 0;
}
