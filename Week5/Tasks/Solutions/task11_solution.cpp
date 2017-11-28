// УП-практикум, спец.Информатика, 6-та група, Седмица 5
#include <iostream>
using namespace std;

const int MAX_LENGTH = 7;

void insert_value(int [], const int, const int);
void fill_array(int []);
void print_array(const int []);

int main(){
  int array[MAX_LENGTH];
  fill_array(array);

  int value;
  cout << "Enter a value to insert:";
  cin  >> value;

  int value_index;
  cout << "Enter a postion [0-" << MAX_LENGTH << "):";
  cin  >> value_index;

  insert_value(array, value, value_index);
  print_array(array);

  return 0;
}


// Описание:
//     Вмъква даден елемент на дадена позиция в масив, като измества
//     елементите вдясно от него (включително елемента, чието място заема)
//     надясно с една позиция.
// Входни параметри на функцията:
//     -int array[] - указател към int масив
//     -const int value - стойност за вмъкване
//     -const int value_index - индекс за вмъкване на стойността
void insert_value(int array[], const int value, const int value_index){
  // Ако индекса не е в границите [0, MAX_LENGTH), не вмъкваме нищо:
  if((value_index<0) || (value_index>=MAX_LENGTH)) return;
  for(int i=MAX_LENGTH-1; i > value_index; i--){
    // Започваме да вървим по масива отзад напред,
    // като всеки елемент заместваме с предходния му:
    array[i] = array[i-1];
  }
  // На "освободената" позиция поставя елемента:
  array[value_index] = value;
}


void fill_array(int array[]){
  cout << "Enter array`s contents (length " << MAX_LENGTH << "):\n";
  for(int i=0; i < MAX_LENGTH; i++){
    cout << "[" << i << "]=";
    cin  >> array[i];
  }
}


void print_array(const int array[]){
  for (int i=0; i < MAX_LENGTH; i++) {
    cout << "|" << array[i] << "|" << " ";
  }
  cout << "\n";
}
