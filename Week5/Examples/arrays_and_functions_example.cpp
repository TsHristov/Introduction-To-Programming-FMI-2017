// УП-практикум, спец.Информатика, 6-та група, Седмица 5
#include <iostream>
using namespace std;

// Декларираме прототипи на всички функции, които ще използваме
// по-надолу в програмата:
int max_element(int [], int);
void fill_array(int [], int);
void print_array(int [], int);
void reverse_array(int [], int [], int);

int main(){
  const int array_size = 5;
  int numbers[array_size];
  int numbers_reversed[array_size];
  
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

// Дефинираме функциите, които декларирахме преди main():
int max_element(int array[], const int size){
  int max = array[0];
  for(int i=1; i < size; i++){
    if (array[i] > max) max = array[i];
  }
  return max;
}

void fill_array(int array[], int array_size){
  cout << "Enter array`s contents:\n";
  for(int i=0; i < array_size; i++){
    cout << "[" << i << "]=";
    cin  >> array[i];
  }
}

void print_array(int array[], int array_size){
  for (int i=0; i < array_size; i++) {
    cout << "[" << i << "]=" << array[i] << "\n";
  }
}

void reverse_array(int original[], int reversed[], int size){
  for(int i=0, j=size-1; i < size && j >= 0; i++, j--){
    reversed[i] = original[j];
  }
}
