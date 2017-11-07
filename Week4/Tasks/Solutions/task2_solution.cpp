// УП-практикум, спец.Информатика, 6-та група, Седмица 4
#include <iostream>
using namespace std;

int main(){
  int length;
  cout << "length=";
  cin  >> length;

  bool odds  = true;
  bool evens = true;
  int value;
  
  for(int i=0; i < length; i++){
    cin >> value;
    (value&1) ? evens = false : odds = false;
  }

  if (evens) cout << "all are even\n";
  else if (odds) cout << "all are odds\n";
  else cout << "mixed\n";

  return 0;
}
