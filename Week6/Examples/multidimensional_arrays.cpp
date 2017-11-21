// УП-практикум, спец.Информатика, 6-та група, Седмица 6
#include <iostream>
using namespace std;

#define ROWS 2
#define COLUMNS 2

void fill_matrix(int[][COLUMNS]);
void print_matrix(const int[][COLUMNS]);
void max_and_min(const int[][COLUMNS], int&, int&);


int main(){
  int matrix[ROWS][COLUMNS]; 

  // Не подаваме големината на двумерния масив,
  // тъй като сме я дефинирали (define) най-отгоре
  // на програмата ни, и така тя е видима за всички
  // функции.
  fill_matrix(matrix);


  // Пример за функция, която приема аргументите си по
  // псевдоним(&) и ги променя.
  // В случая подаваме min и max като псевдоними
  // и функцията max_and_min работи директно с тях
  // без да им прави копие и по този начин
  // всяка тяхна промяна от страна на функцията ще
  // бъде приложена върху тях.
  int min, max;
  max_and_min(matrix, min, max);

  print_matrix(matrix);

  cout << "min:" << min << "\n";
  cout << "max:" << max << "\n";

  return 0;
}

// Описание:
//     Въвежда елементите на дадена матрица.
// Входни параметри на функцията:
//     -int matrix[][COLUMNS] - указател към масив от указатели,
//                              с дължина COLUMNS
void fill_matrix(int matrix[][COLUMNS]){
  cout << "Enter matrix`s contents:\n";
  for(int i=0; i < ROWS; i++){
    for(int j=0; j < COLUMNS; j++){
      cout << "[" << i << "][" << j << "]=";
      cin >> matrix[i][j];
    }
  }
  cout << "\n";
}

// Описание:
//     Изкарва елементите на даден масив на конзолата.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
void print_matrix(const int matrix[][COLUMNS]){
  cout << "Matrix`s contents:\n";
  for(int i=0; i < ROWS; i++){
    cout << "\n";
    for(int j=0; j < COLUMNS; j++){
      cout << "[" << i << "][" << j << "]=" \
	   << matrix[i][j] << " ";
    }
  }
  cout << "\n";
}

// Описание:
//     Намира максималния и минималния елемент в матрица.
// Странични ефекти:
//     Приема два аргументи по псевдоним - min и max.
//     Променя тяхната стойност, съответно с минималния и
//     максималния елемент в матрицата.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
void max_and_min(const int matrix[][COLUMNS],int &min, int &max){
  // Като за начало нека минималния и максималния елемент
  // са първия елемент в масива:
  min = max = matrix[0][0]; 
  for(int i=0; i < ROWS; i++){
    cout << "\n";
    for(int j=0; j < COLUMNS; j++){
      if(max < matrix[i][j]) max = matrix[i][j];
      if(min > matrix[i][j]) min = matrix[i][j];
    }
  }
}
