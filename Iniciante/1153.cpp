#include <iostream>
using namespace std;

int main() {
  int X;

  do {
    cin >> X;
    if (X == 0) continue;
    
    for (int i = 1; i <= X; ++i) cout << i << (i != X ? " " : "");
    cout << endl;
  } while (X != 0);

  return 0;
}