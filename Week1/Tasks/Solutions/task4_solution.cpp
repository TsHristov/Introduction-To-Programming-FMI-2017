#include <iostream>
using namespace std;

int main()
{
  int number;
  cout << "Enter positive number:";
  cin  >> number;

  // Ако сме въвели отрицателно число,
  // подканваме потребителя да въведе положително:
  while(number < 0)
  {
    cout << "Enter positive number:";
    cin  >> number;
  }
  
  // Ще използваме 16 бита за да представим числото,
  // тъй като един int е 4 байта.
  int remainders[16] = {0,};
  
  // Индекса е 15, тъй като ще започнем да
  // запълваме масива отзад напред:
  int index = 15;
  
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
    // Намаляме индекса за да се движим назад по масива:
    --index;
    // Разделяме числото на 2:
    number = number / 2;
  }
  
  // Изкарваме битовете на числото:
  for(int i=0; i < 16; i++)
  {
    cout << remainders[i];
  }
  
  cout << "\n";
  return 0;
}
