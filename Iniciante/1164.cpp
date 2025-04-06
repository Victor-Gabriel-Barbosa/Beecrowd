#include <iostream>
using namespace std;

bool isPerfeito(int X) {
  int soma = 0;
  for (int i = 1; i < X; i++) if (X % i == 0) soma += i;
  return soma == X;
}

int main() {
  int N, X;

  cin >> N;
  cin.ignore();

  while (N--) {
    cin >> X;
    cin.ignore();
    cout << X << " " << (isPerfeito(X) ? "eh" : "nao eh") << " perfeito" << endl;
  }

  return 0;
}