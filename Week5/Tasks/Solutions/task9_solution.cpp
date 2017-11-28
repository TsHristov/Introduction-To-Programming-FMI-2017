// УП-практикум, спец.Информатика, 6-та група, Седмица 5
#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

bool is_small_letter(char);
bool is_capital_letter(char);
void enter_string(char [], const int);
void caesar_shift(char [], const int, const int);

 
int main(){
  const int LENGTH = 4;

  // Въвеждаме някакъв текст с фиксирана дължина:
  char text[LENGTH];
  enter_string(text, LENGTH);

  // Въвеждаме стъпката на "криптиране":
  int shift;
  cout << "Enter Caesar (left) shift:";
  cin  >> shift;
  caesar_shift(text, LENGTH, shift);

  cout << "Encrypted string:" << text << "\n";
  
  return 0;
}


// Описание:
//      Въвежда съдържанието на даден char масив.
//      (Добавя символа '\0' за край на стринг на последна позиция в масива).
// Входни параметри на функцията:
//     -char text[] - указател към char масив
//     -const int length - дължина на char масива
void enter_string(char text[], const int length){
  cout << "Enter string with length " << length -1 << ":";
  for(int i=0; i<length-1; i++){
    cin >> text[i];
  }
  // Със символа '\0' указваме края на текстов низ:
  text[length-1] = '\0';
}


// Описание:
//      "Криптира" char масив, използвайки Цезарово Криптиране.
//      Съгласно ASCII кода на дадена буква я замества с нова на
//      shift отмествания спрямо нея.
// Входни параметри на функцията:
//     -char text[] - указател към char масив
//     -const int length - дължина на char масива
//     -const int shift  - стъпка на "кодиране"
// В момента реализацията на функцията прилага само отместване
// наляво. Опитайте се да го направите в произволна посока.
void caesar_shift(char text[], const int length, const int shift){
  int letter = 0;
  for(int i=0; i < length-1; i++){
    // Тъй като в момента отместването е само надясно,
    // то от ASCII стойността на текущия елемент в масива
    // изваждаме shift (отместването). Така получаваме, новата
    // стойност.
    letter = text[i]-shift;
    if ((letter - 'A' < 0) || (letter - 'a' < 0)) {
      // Ако сме прескочили началото на азбуката, било то 'A'
      // или 'a', то добавяме 26 за да "стигнем" до новата стойност:
      text[i] = letter + ALPHABET_SIZE;
    } else {
      text[i] = letter;
    }
  }
}
