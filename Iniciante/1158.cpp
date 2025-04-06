#include <iostream>
using namespace std;

int main() {
  int N, X, Y, sequencia;
  cin >> N;

  while (N--) {
    int soma = 0;
    cin >> X >> Y;

    soma = (X % 2) ? X : X + 1;
    sequencia = soma;

    for (int i = 0; i < Y - 1; i++) {
      sequencia += 2;
      soma += sequencia;
    }

    cout << soma << endl;
  }

  return 0;
}