// УП-практикум, спец.Информатика, 6-та група, Седмица 8
#include <iostream>
using namespace std;


int main(){
  const int size = 5;
  int array[size];

  // Декларираме указател, който да сочи към началото на масива:
  int * pointer = array;

  // Променяме стойността към която сочи указателя (в случая първият елемент
  // от масива), след което го инкрементираме (преместваме към следващия адрес):
  *(pointer++) = 10;
  *pointer = 20;

  // Вземаме адреса на 3-тия елемент от масива и пренасочваме указателя към него:
  pointer = &array[2];
  *pointer = 30;

  // Отместваме указателя с 3 позиции спрямо началото на масива (т.е. намираме
  // се на 4-тия елемент от масива):
  pointer = array + 3;
  *pointer = 40;
  int * other = NULL;

  // Декларираме друг указател, който да сочи към началото на масива:
  other = array;

  // Отместваме го с 4 позиции (адреса) и присвояваме стойността 50 на
  // сочения адрес:
  *(other + 4) = 50;
  pointer = array;

  // Проверка дали адресите на двата указателя са едни и същи:
  if(pointer == other){
    cout << "Addresss of pointer: " << pointer << "\n";
    cout << "Address of other: " << other << "\n";
    cout << "Address of array: " << array << "\n";
    cout << "Address of head of array: " << &array[0] << "\n";
  }

  // Какво прави следния код? :)
  int * start = array;
  int * end   = array + size;
  while(start != end) {++*(start++);}

  // A този?
  for(int * i = array; i < array + size; ++i) cout << *i << " ";
  cout << "\n";
  
  return 0;
}
