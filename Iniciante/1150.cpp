#include <iostream>
using namespace std;

int main() {
  int X, Z, soma = 0, cont = 1;

  cin >> X >> Z;
  while (Z <= X) cin >> Z;

  soma = X;
  while (Z > soma) {
    soma += ++X;
    cont++;
  }
  
  cout << cont << endl;

  return 0;
}