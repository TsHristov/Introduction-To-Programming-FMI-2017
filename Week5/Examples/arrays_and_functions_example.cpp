// УП-практикум, спец.Информатика, 6-та група, Седмица 5
#include <iostream>
using namespace std;

// Декларираме прототипи на всички функции, които ще използваме.
// Задаваме типа на параметрите, които те приемат, както и типа на
// връщания резултат.
int max_element(const int [], const int);
void fill_array(int [], const int);
void print_array(const int [], const int);
void reverse_array(const int [], int [], const int);

int main(){
  // Дължината на масив в C++ трябва да
  // е константна, затова декларираме array_size
  // като const:
  const int array_size = 5;
  // Създаваме два масива, съдържащи целочислени променливи (int),
  // и дължина array_size (5).
  int numbers[array_size];
  int numbers_reversed[array_size];

  // Извикваме съответните функции за манипулация на масивите:
  fill_array(numbers, array_size);
  cout << "Contents of numbers array:\n";
  print_array(numbers, array_size);
  reverse_array(numbers, numbers_reversed, array_size);
  cout << "Contents of reversed numbers array:\n";
  print_array(numbers_reversed, array_size);
  cout << "Max element in the array: " \
       << max_element(numbers, array_size) << "\n";
  
  return 0;
}

// Дефинираме функциите, които декларирахме преди main:

// Описание:
//     Намира максималния елемент в даден масив.
// Входни параметри на функцията:
//     -int array[] - указател към масив
//     -const int array_size - големината на масива
// Връщан резултат:
//     -int max - максималния елемент в даден масив
int max_element(const int array[], const int array_size){
  int max = array[0];
  for(int i=1; i < array_size; i++){
    if (array[i] > max) max = array[i];
  }
  return max;
}

// Описание:
//     Въвежда съдържанието на масива елемент по елемент.
// Входни параметри на функцията:
//     -int array[] - указател към масив
//     -const int array_size - големината на масива
void fill_array(int array[], const int array_size){
  cout << "Enter array`s contents:\n";
  for(int i=0; i < array_size; i++){
    cout << "[" << i << "]=";
    cin  >> array[i];
  }
}

// Описание:
//     Изкарва на конзолата, елементите на даден масив.
// Входни параметри на функцията:
//     -int array[] - указател към масив
//     -const int array_size - големината на масива
void print_array(const int array[], const int array_size){
  for (int i=0; i < array_size; i++) {
    cout << "[" << i << "]=" << array[i] << "\n";
  }
}

// Описание:
//      Обръща съдържанието на подаден масив в друг.
// Входни параметри на функцията:
//     -int original[] - указател към оригиналния масив, който ще обърнем
//     -int reversed[] - указател към резултатния масив, който ще съдържа обърнатия original
//     -const int array_size - дължината на двата масива
void reverse_array(const int original[], int reversed[], const int array_size){
  for(int i=0, j=array_size-1; i < array_size && j >= 0; i++, j--){
    reversed[i] = original[j];
  }
}
