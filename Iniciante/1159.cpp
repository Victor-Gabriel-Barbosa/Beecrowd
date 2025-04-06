#include <iostream>
using namespace std;

int main() {
  int X;

  do {
    cin >> X;
    cin.ignore();
    if (X == 0) continue;

    int sequencia = !(X % 2) ? X : X + 1;
    int soma = sequencia;

    for (int i = 0; i < 4; i++) {
      sequencia += 2;
      soma += sequencia;
    }

    cout << soma << endl;
  
  } while (X != 0);

  return 0;
}