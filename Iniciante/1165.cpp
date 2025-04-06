#include <iostream>
using namespace std;

bool isPrimo(int X) {
  for (int i = 2; i < X; i++) if (X % i == 0) return false;
  return true;
}

int main() {
  int N, X;

  cin >> N;
  cin.ignore();

  while (N--) {
    cin >> X;
    cin.ignore();
    cout << X << " " << (isPrimo(X) ? "eh" : "nao eh") << " primo" << endl;
  }

  return 0;
}