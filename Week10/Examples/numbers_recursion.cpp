#include <iostream>
#include <math.h>
using namespace std;

// Описание:
//      Обръща дадено цяло число.
//      Пример: Вход: 1234, Изход: 4321.
// Входни параметри на функцията:
//     -int n - горна граница на интервала
// Връщан резултат:
//     -unsigned int - сумата на числата в интервала
unsigned int reverse(int number, int reversed=0){
  if (number == 0) return reversed;
  return reverse(number/10, reversed * 10 + number % 10);
}

// Описание:
//      Превръща дадено число в двоично, рекурсивно.
//      Пример: Вход: 5, Изход: 101
// Входни параметри на функцията:
//     -int number - числото, подадено като вход на функцията
//     -int step   - стъпка
// Връщан резултат:
//     -unsigned int - двоично представяне числото
unsigned int binary(int number, int step=0){
  if (number == 0) return 0;
  return number % 2 * pow(10,step) + binary(number/2, step+1);
}

// Описание:
//      Намира факториел на дадено число. Тук нямаме опашкова рекурсия,
//      тъй като имаме отложена операция.
// Входни параметри на функцията:
//     -unsigned int n - число
// Връщан резултат:
//     -unsigned int - факториела на даденото число
unsigned int factorial(unsigned int n){
  if (n == 0) return 1;
  return n*factorial(n-1);
}

// Описание:
//      Намира факториел на дадено число, използвайки опашкова рекурсия.
// Входни параметри на функцията:
//     -unsigned int n - число
//     -usigned  int x - число, което ще пази междинните стойности
//                       между извикванията на функцията
// Връщан резултат:
//     -unsigned int - факториела на даденото число
unsigned int factorial_tail(unsigned int n, unsigned int x=1){
  if (n == 0) return x;
  return factorial_tail(n-1,n*x);
}

// Описание:
//      Намира сумата на числата в интервала [1,n].
//      Итеративен вариант.
// Входни параметри на функцията:
//     -int n - горна граница на интервала
// Връщан резултат:
//     -int - сумата на числата в интервала
unsigned int iterative_sum(int n){
  int sum = 0;
  for (int i = 1; i <= n; ++i) sum += i;
  return sum;
}

// Описание:
//      Намира сумата на числата в интервала [1,n].
//      Рекурсивен вариант. Изразходва се допълнителна памет
//      , тъй като се конструира нова стекова рамка,
//      при всяко рекурсивно извикване на функцията.
// Входни параметри на функцията:
//     -int n - горна граница на интервала
// Връщан резултат:
//     -unsinged int - сумата на числата в интервала
unsigned int recursive_sum(int n){
  if (n == 1) return 1;
  return n + recursive_sum(n-1);
}

int main(){
    cout << reverse(1234) << "\n";
    cout << binary(123) << "\n";
    cout << factorial(5) << "\n";
    cout << factorial_tail(5) << "\n";
    cout << iterative_sum(10) << "\n";
    cout << recursive_sum(10) << "\n";
    return 0;
}
