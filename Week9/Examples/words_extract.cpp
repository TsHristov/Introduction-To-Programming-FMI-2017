#include <iostream>
using namespace std;

bool is_letter(char c);
size_t words_count(const char *);
size_t words_count_delimeter(const char *, const char&);
size_t word_size(const char *&);
char** extract_words(const char *, int &);

int main(){
  const char *space_delimited_text = "Some     random text  here";
  cout << "Count of words: " << words_count(space_delimited_text) << "\n";

  // Намираме броя думи в текст, разделени с определен разделител:
  const char *dot_delimited_text = "Some...random.text.here";
  cout << "Count of words (using delimeter): " << words_count_delimeter(dot_delimited_text, '.') << "\n";

  // Изваждаме отделните думи от random_text:
  int words_cnt;
  char **words = extract_words(space_delimited_text, words_cnt);
  
  for(int i=0; i < words_cnt; i++){
    cout << "Word No " << i + 1 << ":" << words[i] << "\n";
  }

  // Обърнете внимание, на начина по който трием паметта:
  for(int i=0; i < words_cnt; i++){
    // Трием всеки един от елементите на масива,
    // който е бил заделен с new:
    delete[] words[i];
  }
  // Накрая трием и самия масив от думи:
  delete[] words;

  return 0;
}


// Описание:
//      Помощна функция, която проверява дали даден символ е буква или не.
// Входни параметри на функцията:
//     -char c - символ
// Връщан резултат:
//     -bool - дали символа е буква или не
bool is_letter(char c){
  // Проверяваме ASCII кода на c:
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
         
}


// Описание:
//     Връща броя думи в даден символен низ. Дума е символен низ
//     съставен само от букви - големи и малки.
// Входни параметри на функцията:
//     -const char *text - указател към символeн низ
// Връщан резултат:
//     -size_t - броя думи в символния низ
size_t words_count(const char *text){
  size_t count = 0;
  while(*text){
    // Докато символите са букви, изместваме указателя:
    while(*text && is_letter(*text)) ++text;
    // Край на дума => броим срещнатата дума:
    ++count;
    // Ако след това има символ, който не е буква, то изместваме указателя:
    while(*text && !is_letter(*text)) ++text;
  }
  return count;
}


// Описание:
//     Връща броя думи в даден символен низ разделени с разделител
//     delimeter.
// Входни параметри на функцията:
//     -const char *text - указател към символeн низ
//     -const char &delimeter - псевдоним на подадения разделител,
//                              това ни позволява да подаваме произволен char като разделител на дума :)
// Връщан резултат:
//     -size_t - броя думи в символния низ
size_t words_count_delimeter(const char *text, const char& delimeter=' '){
  size_t count = 0;
  while(*text){
    // Ако текущия символ е разделителя, изместваме указателя,
    // докато не стигнем начало на дума:
    if(*text != delimeter) ++text;
    // Ако сме попаднали на първо срещане на разделител, то броим думата:
    if(*text == delimeter) ++count;
    // Ако след това има още разделители, изместваме указателя:
    while(*text == delimeter) ++text;
  }
  return count+1;
}


// Описание:
//     Намира дължината да дадена дума.
// Входни параметри на функцията:
//     -const char *&start - псевдоним на указателя към началото на думата
// Връщан резултат:
//     -size_t  - дължината на дума, без '\0'
size_t word_size(const char *&start){
  while(!is_letter(*start)) ++start;
  const char *end = start;
  while(is_letter(*end++));
  return end - start - 1;
}


// Описание:
//     По даден символен низ извлича думите от него (дума е поредица от букви).
//     Създава масив от всички отделни думи.
// Входни параметри на функцията:
//     -const char *text - указател към символния низ
//     -int &words_cnt - псевдоним, чрез който ще бъде върнат броя думи в низа
// Връщан резултат:
//     -char** - масив от символни низове, които са отделните думи в първоначалния низ
char** extract_words(const char *text, int &words_cnt){
  // Намираме броя отделни думи в символния низ:
  words_cnt = words_count(text);

  // Заделяме масив от char* указатели с големина броя думи в текста,
  // всеки от тях ще сочи към отделна дума:
  char** words = new (nothrow) char*[words_cnt];
  if (!words) { return NULL; }

  // За всяка една отделна дума от текста:
  for(int i=0; i < words_cnt; ++i){
    // Намираме нейната дължина:
    size_t word_length = word_size(text);

    // Заделяме памет за думата и я записваме в масива:
    words[i] = new (nothrow) char[word_length + 1];
    if (!words[i]) { return NULL; };
    int j=0;
    for(; j < word_length; j++){
      // Копираме съдържанието на думата от оригиналния низ,
      // в масива за отделната дума:
      words[i][j] = *text++;
    }
    // Не забравяйте '\0'!
    words[i][j] = '\0';
  }
  return words;
}
