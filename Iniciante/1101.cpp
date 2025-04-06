#include <iostream>
using namespace std;

int main() {
  int x, y, max, min, soma;

  do {
    cin >> x >> y;
    cin.ignore();

    if (x <= 0 || y <= 0) continue;

    max = (x > y) ? x : y;
    min = (x < y) ? x : y;

    soma = 0;
    for (int i = min; i <= max; i++) {
      soma += i;
      cout << i << " ";
    }
    cout << "Sum=" << soma << endl;

  } while (x > 0 && y > 0);

  return 0;
}