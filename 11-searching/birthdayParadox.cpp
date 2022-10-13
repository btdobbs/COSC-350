#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
  srand((unsigned) time(NULL));
  const short minExperiments = 100;
  const short daysInYear = 365;
  for(short n = 5; n <= 100; n+=5)
  {
    short birthdaysMatched = 0;
    for(short i = 0; i < minExperiments; i++)
    {
      //should be able to do this with a 46 byte bit vector
      short birthdays[daysInYear] = {};
      for(short j = 0; j < n; j++)
      {
        short birthday = rand() % daysInYear;
        birthdays[birthday]++;
        if (birthdays[birthday] > 1)
        {
          birthdaysMatched++;
          break;
        }
      }
    }
    cout << "Pardox test for n = " << n << ": "
         << (float)birthdaysMatched/(float)minExperiments * 100.0
         << "% of experiments had matches\n";
  }
  return 0;
}
