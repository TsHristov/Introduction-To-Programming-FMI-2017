// УП-практикум, спец.Информатика, 6-та група, Седмица 4
#include <iostream>
using namespace std;

int main(){
  int n;
  cout << "n=";
  cin  >> n;

  long long int i = 0, j = 1;
  long long int current = 0;

  switch(n){
  case 0:
    current = i;
    break;
  case 1:
    current = j;
    break;
  }
  
  for(int counter=1; counter < n ; i=j, j=current, counter++){
    current = i + j;
  }

  cout << "nth fibonacci number: " << current << "\n";
  
  return 0;
}
