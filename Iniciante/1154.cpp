#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int idade, soma = 0, cont = 0;

  cin >> idade;
  while (idade >= 0) {
    soma += idade;
    cont++;
    cin >> idade;
  }

  cout << fixed << setprecision(2) << (double) soma / cont << endl;
  
  return 0;
}