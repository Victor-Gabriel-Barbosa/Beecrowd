#include <iostream>
using namespace std;

int main() {
  int X, Y, min, max;
  cin >> X >> Y;
  cin.ignore();

  max = (X > Y) ? X : Y;
  min = (X < Y) ? X : Y;
  for (int i = min + 1; i < max; i++) if (i % 5 == 2 || i % 5 == 3) cout << i << endl;
  
  return 0;
}