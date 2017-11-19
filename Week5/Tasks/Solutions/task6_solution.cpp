#include <iostream>
using namespace std;

#define MAX_LENGTH 5

int nth_biggest(int [], const int, int);
void selection_sort(int [], const int);
void swap(int [], int, int);
void fill_array(int [], const int);
void print_array(const int [], const int);

int main(){
  int array[MAX_LENGTH];
  int n;
  
  do{
    cout << "n=";
    cin  >> n;
  }while(n > MAX_LENGTH);
  
  fill_array(array, MAX_LENGTH);
  int nth = nth_biggest(array, MAX_LENGTH, n);

  switch(n){
  case 1:
    cout << n << "st biggest element: " <<  nth << "\n";
    break;
  case 2:
    cout << n << "nd biggest element: " << nth << "\n";
    break;
  case 3:
    cout << n << "rd biggest element: " << nth << "\n";
    break;
  default:
    cout << n << "th biggest element: " << nth << "\n";
    break;
  }
  
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

// Описание:
//      Връща n-тия най-голям елемент в масив.
// Входни параметри на функцията:
//     -const int array[] - указател към масив
//     -const int array_length - големината на масива
//     -int n - поредност на елемента
// Връщан резултат:
//     -int nth - n-тия най-голям елемент в масив.
int nth_biggest(int array[], const int array_length, int n){
  // Сортираме масива
  selection_sort(array, array_length);
  // Вземането на n-тия най-голям вече е тривиално:
  return array[array_length-n];
}

// ... 
void fill_array(int array[], const int array_length){
  cout << "Enter array`s contents (length 5):\n";
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

