#include <iostream>
using namespace std;

size_t strlen(const char *text, const char& end='\0'){
  const char *start = text;
  while(*start++ != end);
  return start - text - 1;
}

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

bool is_letter(char c){
  // Проверяваме ASCII кода на c:
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
         
}

size_t words_count(const char *text){
  size_t count = 0;
  while(*text){
    while(*text && is_letter(*text)) ++text;
    ++count;
    while(*text && !is_letter(*text)) ++text;
  }
  return count;
}

size_t words_count_delimeter(const char *text, const char& delimeter=' '){
  size_t count = 0;
  while(*text){
    if(*text != delimeter) ++text;
    if(*text == delimeter) ++count;
    while(*text == delimeter) ++text;
  }
  return count+1;
}

char** extract_words(const char *text, int &words_cnt){
  words_cnt = words_count(text);
  // Заделяме масив от char* указатели с големина броя думи в текста:
  char** words = new (nothrow) char*[words_cnt];
  if (!words) { return NULL; }
  // За всяка една дума от текста:
  for(int i=0; i < words_cnt; ++i){
    // Ако още не сме в началото на дума,
    // изместваме указателя, така че да стигнем до начало:
    while(!is_letter(*text)) ++text;
    // Правим друг указател да сочи към началото на думата,
    // той ще ни трябва за да намерим дължината в последствие:
    const char *start = text;
    size_t word_length = 0;
    // Докато символа е буква инкрементираме указателя:
    while(is_letter(*start++));
    // Намираме дължината на конкретната дума, чрез адресна аритметика:
    word_length = start - text - 1;

    // Заделяме памет за думата и я записваме в масива:
    words[i] = new (nothrow) char[word_length + 1];
    start = text;
    int j=0;
    for(; j < word_length; j++){
      words[i][j] = *start++;
    }
    words[i][j] = '\0';
    text = start;
  }
  return words;
}

int main(){
  const char *random_text = "Some  b   random text  here";
  cout << "Count of words (using delimeter): " << words_count_delimeter(random_text) << "\n";
  cout << "Count of words: " << words_count(random_text) << "\n";

  int words_cnt;
  char **words = extract_words(random_text, words_cnt);
  
  for(int i=0; i < words_cnt; i++){
    cout << "Word: " << words[i] << "\n";
  }
  
  int size;
  cout << "Enter string size: ";
  cin >> size;
  char * text = new (nothrow) char[size+1];

  if(!text) {return -1;}

  for(int i=0; i < size; i++){
    cin >> text[i];
  }
  text[size] = '\0';

  cout << text << "\n";

  char *reversed = reverse(text);
  cout << reversed << "\n";

  delete[] text;
  delete[] reversed;

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
