// УП-практикум, спец.Информатика, 6-та група, Седмица 5
#include <iostream>
using namespace std;

// Декларираме прототипи на всички функции, които ще използваме.
// Задаваме типа на параметрите, които те приемат, както и типа на
// връщания резултат.
int max_element(const int [], const int);
int min_element(const int [], const int);
void fill_array(int [], const int);
void print_array(const int [], const int);
void reverse_array(const int [], int [], const int);

int main(){
  // Дължината на масив в C++ трябва да
  // е константна, затова декларираме array_length
  // като const:
  const int array_length = 5;
  
  // Създаваме два масива, съдържащи целочислени променливи (int),
  // и дължина array_length (5).
  int numbers[array_length];
  int numbers_reversed[array_length];

  // Извикваме съответните функции за манипулация на масивите:
  fill_array(numbers, array_length);
  cout << "Contents of numbers array:\n";
  print_array(numbers, array_length);

  // Намиране на максимален/минимален елемент в масив:
  int max = max_element(numbers, array_length);
  int min = min_element(numbers, array_length);
  cout << "Max element in the array: " \
       << max_element(numbers, array_length) << "\n";
  cout << "Min element in the array: " \
       << min_element(numbers, array_length) << "\n";

  // Обръщане на масив, чрез помощен:
  reverse_array(numbers, numbers_reversed, array_length);
  cout << "Contents of reversed numbers array:\n";
  print_array(numbers_reversed, array_length);

  return 0;
}

// Дефинираме функциите, които декларирахме преди main:

// Описание:
//     Намира максималния елемент в даден масив.
// Входни параметри на функцията:
//     -const int array[] - указател към масив
//     -const int array_length - големината на масива
// Връщан резултат:
//     -int max - максималния елемент в даден масив
int max_element(const int array[], const int array_length){
  // Пример:
  //     Входен масив: | 1 | 2 | 3 | 0 | 7 | 2 |
  //     Индекси:        0   1   2   3   4   5
  //     Максимален елемент на индекс: 4
  int max = array[0]; // min = array[0] = 1
  for(int i=1; i < array_length; i++){
    if (array[i] > max) max = array[i];
  }
  return max;
}

// Описание:
//      Намира минималния елемент в даден масив.
// Входни параметри на функцията:
//     -const int array[] - указател към масив
//     -const int array_length - големината на масива
// Връщан резултат:
//     -int min - минималния елемент в даден масив
int min_element(const int array[], const int array_length){
  // Пример:
  //     Входен масив: | 1 | 2 | 3 | 0 | 7 | 2 |
  //     Индекси:        0   1   2   3   4   5
  //     Минимален елемент на индекс: 3
  int min = array[0]; // min = array[0] = 1
  for(int i=1; i<array_length; i++){
    if(array[i] < min) min = array[i];
  }
  return min;
}

// Описание:
//     Въвежда съдържанието на масива елемент по елемент.
// Входни параметри на функцията:
//     -int array[] - указател към масив
//     -const int array_length - големината на масива
void fill_array(int array[], const int array_length){
  cout << "Enter array`s contents:\n";
  for(int i=0; i < array_length; i++){
    cout << "[" << i << "]=";
    cin  >> array[i];
  }
}

// Описание:
//     Изкарва на конзолата, елементите на даден масив.
// Входни параметри на функцията:
//     -const int array[] - указател към масив
//     -const int array_length - големината на масива
void print_array(const int array[], const int array_length){
  for (int i=0; i < array_length; i++) {
    cout << "|" << array[i] << "|" << " ";
  }
  cout << "\n";
}

// Описание:
//      Обръща съдържанието на подаден масив в друг.
// Входни параметри на функцията:
//     -const int original[] - указател към оригиналния масив, който ще обърнем
//     -int reversed[] - указател към резултатния масив, който ще съдържа обърнатия original
//     -const int array_length - дължината на двата масива
void reverse_array(const int original[], int reversed[], const int array_length){
  // Вход:
  //     Входен масив(original): | 1 | 2 | 3 | 0 | 7 | 2 |
  //     Входен масив(reversed): | 0 | 0 | 0 | 0 | 0 | 0 |
  for(int i=0, j=array_length-1; i < array_length && j >= 0; i++, j--){
    reversed[i] = original[j];
  }
  // Изход (функцията е void, но променя подадения й параметър reversed)
  //     Входен масив(original): | 1 | 2 | 3 | 0 | 7 | 2 |
  //     Входен масив(reversed): | 2 | 7 | 0 | 3 | 2 | 1 |
}
