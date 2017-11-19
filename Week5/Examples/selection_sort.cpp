#include <iostream>
using namespace std;

#define MAX_LENGTH 6

void selection_sort(int [], const int);
void swap(int [], int, int);
void fill_array(int [], const int);
void print_array(const int [], const int);

int main(){
  int array[MAX_LENGTH];

  // Въвеждаме масива:
  fill_array(array, MAX_LENGTH);
  cout << "Original: ";
  print_array(array, MAX_LENGTH);

  // Извикваме selection_sort функцията, върху масива
  // за да го сортираме и го извеждаме на конзолата:
  selection_sort(array, MAX_LENGTH);
  cout << "Sorted: ";
  print_array(array, MAX_LENGTH);
  return 0;
}

// Описание:
//      Разменя два елемента в масив.
// Входни параметри на функцията:
//     -int array[] - указател към масив
//     -int i, j - индекси на чиито елементи подлежат на размяна
void swap(int array[], int i, int j){
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

// Описание:
//      Сотира масив по използвайки Selection Sort.
// Входни параметри на функцията:
//     -int array[] - указател към масив
//     -const int array_length - големината на масива
void selection_sort(int array[], const int array_length){
  int min, i, j;
  for(i=0; i<array_length-1; i++){
    min = i;
    for(j=i+1; j<array_length; j++){
      if(array[j] < array[min]){
	min = j;
	swap(array, i, j);
      }
    }
  }
}

// ... 
void fill_array(int array[], const int array_length){
  cout << "Enter array`s contents (length " << MAX_LENGTH << "):\n";
  for(int i=0; i < array_length; i++){
    cout << "[" << i << "]=";
    cin  >> array[i];
  }
}

// ...
void print_array(const int array[], const int array_length){
  for (int i=0; i < array_length; i++) {
    cout << "|" << array[i] << "|" << " ";
  }
  cout << "\n";
}
