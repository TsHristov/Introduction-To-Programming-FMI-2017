// УП-практикум, спец.Информатика, 6-та група, Седмица 5
#include <iostream>
using namespace std;

// Декларираме прототипи на всички функции, които ще използваме.
// Задаваме типа на параметрите, които те приемат, както и типа на
// връщания резултат.
int max_element(const int [], const int);
int min_element(const int [], const int);
int count_evens(const int [], const int);
int count_odds(const int [], const int);
int array_sum(const int [], const int);
int array_product(const int [], const int);
bool monotonic_increasing(const int [], const int);
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

  // Намиране на брой четни/нечетени елементи в масив:
  int evens_count = count_evens(numbers, array_length);
  int odds_count  = count_odds(numbers, array_length);
  cout << "Count of evens:" << evens_count << "\n";
  cout << "Count of odds:" << odds_count << "\n";
  
  // Намиране на сума/произведение на елементи на масив:
  int sum = array_sum(numbers, array_length);
  int product = array_product(numbers, array_length);
  cout << "Sum:" << sum << "\n";
  cout << "Product:" << product << "\n";

  // Проверка дали масива е монотонно растяща редица:
  bool is_monotonic_increasing = monotonic_increasing(numbers, array_length);
  cout << "The array is monotonic increasing sequence: " \
       << ((is_monotonic_increasing) ? "yes\n" : "no\n");
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
//      Намира броя четни елементи в даден масив.
// Входни параметри на функцията:
//     -const int array[] - указател към масив
//     -const int array_length - големината на масива
// Връщан резултат:
//     -int count - брой четни елементи в даден масив
int count_evens(const int array[], const int array_length){
  int count = 0;
  for(int i=0;i<array_length;i++){
    if(array[i] % 2 == 0) count++;
  }
  return count;
}

// Описание:
//      Намира броя нечетни елементи в даден масив.
// Входни параметри на функцията:
//     -const int array[] - указател към масив
//     -const int array_length - големината на масива
// Връщан резултат:
//     -int count - брой нечетни елементи в даден масив
int count_odds(const int array[], const int array_length){
  int count = 0;
  for(int i=0;i<array_length;i++){
    if(array[i] % 2 != 0) count++;
  }
  return count;
}  

// Описание:
//      Проверява дали масива представлява монотонно нарастваща редица.
// Входни параметри на функцията:
//     -const int array[] - указател към масив
//     -const int array_length - големината на масива
// Връщан резултат:
//     -bool is_monotonic_increasing - True/False в зависимост от това
//                                     дали масива е монотонно намаляваща редица. 
bool monotonic_increasing(const int array[], int array_length){
  bool is_monotonic_increasing = true;
  for(int i=0; i<array_length-1; i++){
    if(!(array[i]<=array[++i])) is_monotonic_increasing = false;
  }
  return is_monotonic_increasing;
}

// Описание:
//      Намира сумата на числата в даден масив.
// Входни параметри на функцията:
//     -const int array[] - указател към масив
//     -const int array_length - големината на масива
// Връщан резултат:
//     -int sum - сумата на числата в даден масив
int array_sum(const int array[], const int array_length){
  int sum = 0;
  for(int i=0; i<array_length; i++) {
    sum += array[i];
  }
  return sum;
}

// Описание:
//      Намира произведението на числата в даден масив.
// Входни параметри на функцията:
//     -const int array[] - указател към масив
//     -const int array_length - големината на масива
// Връщан резултат:
//     -int product - произведението на числата в даден масив
int array_product(const int array[], const int array_length){
  int product = 1;
  for(int i=0; i<array_length; i++) {
    product *= array[i];
  }
  return product;
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
