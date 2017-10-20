#include <iostream>
using namespace std;

int main()
{
  int number;
  cout << "Enter positive number:";
  cin  >> number;
  // Ако сме въвели отрицателно число
  // подканваме потребителя да въведе положително:
  while(number < 0)
  {
    cout << "Enter positive number:";
    cin  >> number;
  }  
  // Ще използваме 16 бита за да представим числото,
  // защото един int е 4 байта, или иначе казано 16 бита.
  int remainders[16] = {0,};
  int index = 0;
  
  // Докато числото не е 0:
  while(number)
  {
    // Извеждаме остатъка му при деление на 2:
    if(number%2)
    {
      // Ако остатъка е 1:
      remainders[index] = number%2;
    }
    else
    {
      // Ако остатъка е 0:
      remainders[index] = 0;
    }
    // Увеличаваме индекса за да продължим
    // да пълним масива:
    ++index;
    // Разделяме числото на 2:
    number = number / 2;
  }
  
  // Изкарваме битовете на числото отзад напред:
  for(int i=15; i>=0; i--)
  {
    cout << remainders[i];
  }
  
  cout << "\n";
  return 0;
}
