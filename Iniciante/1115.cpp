#include <iostream>
using namespace std;

int main() {
  int x, y;

  do {
    cin >> x >> y;
    cin.ignore();

    if (x == 0 || y == 0) continue;

    if (x > 0 && y > 0) cout << "primeiro" << endl;
    else if (x < 0 && y > 0) cout << "segundo" << endl;
    else if (x < 0 && y < 0) cout << "terceiro" << endl;
    else cout << "quarto" << endl;
  } while (x != 0 && y != 0);

  return 0;
}