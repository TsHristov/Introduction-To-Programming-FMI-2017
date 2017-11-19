#include <iostream>
using namespace std;

// Друг начин за задаване на големина на статичен масив:
#define MAX_LENGTH 4

void reverse(int [], const int array_length);
void fill_array(int [], const int);
void print_array(const int [], const int);

int main(){
  int array[MAX_LENGTH];
  fill_array(array, MAX_LENGTH);
  print_array(array, MAX_LENGTH);
  reverse(array, MAX_LENGTH);
  print_array(array, MAX_LENGTH);
  return 0;
}

// Описание:
//     Обръща масива, без да използва допълнителен.
// Входни параметри на функцията:
//     -int array[] - указател към масив
//     -const int array_length - големината на масива
void reverse(int array[], const int array_length) { // тук int array[], не е const int array[],
                                                    // тъй като искаме да го променим във функцията.
  double middle = array_length / 2;
  // Разделяме масива на две половини,
  // и разменяме поетапно елементите на първа и последна позиция,
  // докато не се срещнат в средата:
  for(int i=0, j=array_length-1; i < middle, j >= middle; i++, j--){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

// Описание:
//     Въвежда съдържанието на масива елемент по елемент.
// Входни параметри на функцията:
//     -int array[] - указател към масив
//     -const int array_length - големината на масива
void fill_array(int array[], const int array_length){
  cout << "Enter array`s contents (length 5):\n";
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

