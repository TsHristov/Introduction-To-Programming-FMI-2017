#include <iostream>
using namespace std;

int main()
{
  int number;
  cout << "number=";
  cin  >> number;
  // Докато числото не е 0
  while(number)
  {
    // Извеждаме остатъка му при деление на 2:
    cout << number % 2;
    // Разделяме числото на 2:
    number = number / 2;
  }
  cout << "\n";
  return 0;
}
