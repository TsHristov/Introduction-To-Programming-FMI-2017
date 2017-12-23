#include <iostream>
using namespace std;

size_t strlen(const char *, const char&);
char* reverse(const char *);

int main(){
  size_t size;
  cout << "Enter string size (without \'\\0\'): ";
  cin >> size;
  char * text = new (nothrow) char[size+1];
  if(!text) {return -1;}

  int i = 0;
  for(; i < size; i++){
    cin >> text[i];
  }
  text[i] = '\0';
  
  char *reversed = reverse(text);
  cout << "Reversed: " << reversed << "\n";

  delete[] text;
  delete[] reversed;

  return 0;
}

// Описание:
//      Намира дължината на даден символен низ.
// Входни параметри на функцията:
//     -const char *text - указател към символeн низ
// Връщан резултат:
//     -size_t - дължината на символен низ
size_t strlen(const char *start){
  // Ще използваме адресна аритметика за да сметнем дължината.
  // Създаваме указател, който да сочи към началото на символния низ:
  const char *end = start;
  // Местим указателя, докато не сме стигнали '\0'
  while(*++end);
  // Изваждаме адреса на края на низа, от адреса на началото:
  return end - start;
}

// Описание:
//     Връща броя думи в даден символен низ. Дума е символен низ
//     съставен само от букви - големи и малки.
// Входни параметри на функцията:
//     -const char *text - указател към символeн низ
// Връщан резултат:
//     -char * - указател към символен низ, който е обърнатият начален
char* reverse(const char *text){
  int size = strlen(text);
  char *reverse = new (nothrow) char[size + 1];
  if (!reverse) { return NULL; }
  int j=0;
  for(int i=size-1; i>=0 && j < size + 1; i--, j++){
    reverse[j] = text[i];
  }
  reverse[j] = '\0';
  return reverse;
}
