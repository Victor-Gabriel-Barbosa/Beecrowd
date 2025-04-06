#include <iostream>
using namespace std;

int main() {
  int X, Y, min, max, soma = 0;
  cin >> X >> Y;
  cin.ignore();

  max = (X > Y) ? X : Y;
  min = (X < Y) ? X : Y;
  for (int i = min; i <= max; i++) if (i % 13) soma += i;

  cout << soma << endl;
  
  return 0;
}