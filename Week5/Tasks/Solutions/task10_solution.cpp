// УП-практикум, спец.Информатика, 6-та група, Седмица 5
#include <iostream>
using namespace std;

const int MAX_LENGTH = 7;

void remove_value(int [], const int, const int);
void fill_array(int [], const int);
void print_array(const int [], const int);

int main(){
  int array[MAX_LENGTH];
  fill_array(array, MAX_LENGTH);

  int value;
  cout << "Enter value to remove:";
  cin  >> value;

  remove_value(array, MAX_LENGTH, value);
  print_array(array, MAX_LENGTH);

  return 0;
}

// Описание:
//     Проверява дададен елемент value от масив (ако се среща).
//     Изместя елементите вляво от него с една позиция наляво.
//     На последна позиция поставя 0.
// Входни параметри на функцията:
//     -int array[] - указател към int масив
//     -const int array_length - дължина на масива
//     -const int value - стойност за премахване
void remove_value(int array[], const int array_length, const int value){
  for(int i=0; i < array_length; i++){
    if(array[i] == value){
      for(; i < array_length-1; i++) array[i] = array[i+1];
      array[i] = 0;
      break;
    }
  }
}


void fill_array(int array[], const int array_length){
  cout << "Enter array`s contents (length " << array_length << "):\n";
  for(int i=0; i < array_length; i++){
    cout << "[" << i << "]=";
    cin  >> array[i];
  }
}


void print_array(const int array[], const int array_length){
  for (int i=0; i < array_length; i++) {
    cout << "|" << array[i] << "|" << " ";
  }
  cout << "\n";
}
