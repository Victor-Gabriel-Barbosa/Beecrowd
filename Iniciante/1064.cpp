#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double v[6], cont = 0, soma = 0;
  
  for (int i = 0; i < 6; i++) cin >> v[i];
  
  for (int i = 0; i < 6; i++) {
    if (v[i] > 0) {
      cont++;
      soma += v[i];
    }
  }

  cout << cont << " valores positivos" << endl;
  cout << fixed << setprecision(1);
  cout << soma / cont << endl;
  
  return 0;
}