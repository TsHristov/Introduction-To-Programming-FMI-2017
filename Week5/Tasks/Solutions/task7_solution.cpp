// УП-практикум, спец.Информатика, 6-та група, Седмица 5
#include <iostream>
using namespace std;

const int MAX_LENGTH = 7;

void selection_sort(int [], const int);
void swap(int [], int, int);
void copy_array(const int[], int [], const int);
void fill_array(int [], const int);
void print_array(const int [], const int);
bool check_uniqueness(const int [], const int);

int main(){
  int array[MAX_LENGTH];
  fill_array(array, MAX_LENGTH);
  print_array(array, MAX_LENGTH);
  bool uniques_only = check_uniqueness(array, MAX_LENGTH);
  (uniques_only) ? cout << "Uniques only!\n" : \
                   cout << "Not all elements are unique!\n";
}


// Описание:
//     Копира масива source в масива destination.
// Входни параметри на функцията:
//     -const int source[] - указател към масив
//     -const int destination[] - указател към масив
//     -const int array_length - големината на масива
void copy_array(const int source[], int destination[], const int array_length){
  for(int i=0; i<array_length; i++){
    destination[i] = source[i];
  }
}


// Описание:
//     Проверява дали даден масив се състои само от уникални елементи.
// Входни параметри на функцията:
//     -const int array[] - указател към масив
//     -const int array_length - големината на масива
bool check_uniqueness(const int array[], const int array_length){
  // Тъй като не искаме да променяме входния масив,
  // заради проверката за уникални елементи,
  // правим негово копие:
  int array_copy[array_length];
  copy_array(array, array_copy, array_length);
  // Флаг, който установява хипотеза за някакво свойство на
  // масива. В случая, хипотезата е, че всички негови елементи
  // са уникални.
  bool uniques_only = true;
  // Сортираме масива, за да си гарантираме, че ако има
  // два еднакви елемента, то те ще се намират един до друг:
  selection_sort(array_copy, array_length);
  for(int i=0; i<array_length-1; i++){
    // Ако сме се натъкнали на два еднакви елемента, то
    // хипотезата е нарушена:
    if(array_copy[i]==array_copy[i-1]) uniques_only = false;
  }
  return uniques_only;
}


void swap(int array[], int i, int j){
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}


void selection_sort(int array[], const int array_length){
  int min;
  for(int i=0; i<array_length-1; i++){
    min = i;
    for(int j=i+1; j<array_length; j++){
      if(array[j] < array[min]){
	min = j;
	swap(array, i, j);
      }
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
