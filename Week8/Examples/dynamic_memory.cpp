// УП-практикум, спец.Информатика, 6-та група, Седмица 8
#include <iostream>
using namespace std;

void fill_array(int *, const int);
void print_array(const int *, const int);
int * copy_array(const int *, const int);

int main(){
  int size;
  cout << "size=";
  cin >> size;

  int * array = new (nothrow) int[size];
  if (array == NULL) { return -1; }

  fill_array(array, size);
  print_array(array, size);
  
  int * copy = copy_array(array, size);
  print_array(copy, size);
  
  delete[] array;
  delete[] copy;
  return 0;
}

void fill_array(int * array, const int size){
  for(int i=0; i < size; i++){
    cout << "array[" << i << "]=";
    cin >> array[i];
  }
}

void print_array(const int * array, const int size){
  for(int i=0; i < size; i++){
    cout << "array[" << i << "]=" << array[i] << "\n";
  }
}

int * copy_array(const int * original, const int size){
  int * copy  = new (nothrow) int[size];
  if(copy == NULL){
    delete[] original;
    return NULL;
  }
  const int * const start = original;
  const int * const end   = original+size;
  for(const int * i = start; i < end; i++){
    *(copy + *i) = *(int *)(original + *i);
  }
  return copy;
}

