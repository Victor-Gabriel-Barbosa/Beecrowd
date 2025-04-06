#include <iostream>
using namespace std;

int main() {
  int X, Y;
  cin >> X >> Y;

  for (int i = 1; i <= Y; ++i) cout << i << (i % X == 0 ? '\n' : ' ');

  return 0;
}