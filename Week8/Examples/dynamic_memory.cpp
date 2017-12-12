// УП-практикум, спец.Информатика, 6-та група, Седмица 8
#include <iostream>
using namespace std;

void fill_array(int *, const int);
void print_array(const int *, const int);
void copy_array(const int *, int *&, const int);

int main(){
  int size;
  cout << "size=";
  cin >> size;

  // Заделяме памет за масив с големина size.
  // Ако заделянето е успешно, то new връща указател
  // към новозаделената памет.
  int * array = new (nothrow) int[size];
  // Трябва проверим дали заделянето е било успешно!
  if (array == NULL) { return -1; }

  fill_array(array, size);
  print_array(array, size);

  // Създаваме копие на масива, като извикваме функцията
  // copy_array, която връща int*, указател към
  // новозаделен блок памет с размер size и съдържание
  // елементите на array, БЕЗ да променяме array.
  // Тъй като указателят е създаден използвайки new,
  // то имаме отговорността да изтрием паметта, след
  // като приключим работа с него!
  int * copy = NULL;
  copy_array(array, copy, size);
  print_array(copy, size);

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // ТРИЕМ ЗАДАЛЕНЕТА ПАМЕТ, КОГАТО НЕ НИ Е НУЖНА ПОВЕЧЕ:
  delete[] array;
  delete[] copy;
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  return 0;
}

// Описание:
//     Въвежда съдържанието на даден масив.
// Входни параметри на функцията:
//     -int * array    - указател към началото на масив
//     -const int size - големината на масива
// Връщан резултат:
//     -void
void fill_array(int * array, const int size){
  for(int i=0; i < size; i++){
    cout << "array[" << i << "]=";
    // Отиваме на позиция (array + i) и там записваме
    // стойността (*):
    cin >> *(array + i); // Еквивалентен запис на array[i]
  }
}

// Описание:
//     Извежда съдържанието на масив на конзолата.
// Входни параметри на функцията:
//     -const int * array - указател към началото на масив,
//                          const, защото не искаме да променяме елементите на масива!
//     -const int size    - големината на масива
// Връщан резултат:
//     -void
void print_array(const int * array, const int size){
  for(int i=0; i < size; i++){
    cout << "array[" << i << "]=" << array[i] << "\n";
  }
}

// Описание:
//     Прави копие на подаден масив и връща указател към него.
// Входни параметри на функцията:
//     -const int * original - указател към началото на масив,
//                             който ще бъде копиран
//     -int *& copy          - псевдоним на указателя на copy,
//                             Означава, че подаваме адреса на copy
//                             директно, и всяка негова промяна във функцията,
//                             ще бъде видима и отвън.
//     -const int size       - големината на масива
// Връщан резултат:
//     -void
void copy_array(const int * original, int *& copy, const int size){
  copy  = new (nothrow) int[size];
  if(copy == NULL){
    // Ако заделянето на памет е пропаднало,
    // то освобождаваме ресурсите заети до момента:
    delete[] original;
    return;
  }
  for(int i = 0; i < size; ++i){
    *(copy + i) = *(original + i); // Еквивалентно на copy[i] = original[i];
  }
}
