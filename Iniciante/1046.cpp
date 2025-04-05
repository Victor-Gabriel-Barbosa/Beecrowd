#include <iostream>
using namespace std;

int main() {
  int hi, hf;
  
  cin >> hi >> hf;
  cout << "O JOGO DUROU " << ((hi < hf) ? hf - hi : 24 - hi + hf) << " HORA(S)" << endl;
  
  return 0;
}