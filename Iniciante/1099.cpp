#include <iostream>
using namespace std;

int main() {
  int N, x, y, max, min, soma;
  cin >> N;
  cin.ignore();

  while (N--) {
    cin >> x >> y;
    cin.ignore();

    max = (x > y) ? x : y;
    min = (x < y) ? x : y;

    soma = 0;
    for (int i = min + 1; i < max; i++) if (i % 2 != 0) soma += i;

    cout << soma << endl;
  }

  return 0;
}