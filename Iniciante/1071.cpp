#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int x, y, soma = 0;
  
  cin >> x >> y;
  int maior = max(x, y);
  int menor = min(x, y);

  for (int i = menor + 1; i < maior; i++) if (i % 2) soma += i;
  cout << soma << endl;
  
  return 0;
}