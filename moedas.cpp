#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double valorMonetario = 0.0;
  cin >> valorMonetario;

  cout << "NOTAS:" << endl;

  int valorEmCentavos = static_cast<int>(valorMonetario * 100 + 0.5);

  int notasDe25 = valorEmCentavos / 2500;
  valorEmCentavos %= 2500;
  cout << notasDe25 << " nota(s) de R$ 25.00" << endl;

  int notasDe10 = valorEmCentavos / 1000;
  valorEmCentavos %= 1000;
  cout << notasDe10 << " nota(s) de R$ 10.00" << endl;

  int notasDe1 = valorEmCentavos / 100;
  valorEmCentavos %= 100;
  cout << notasDe1 << " nota(s) de R$ 1.00" << endl;

  return 0;
}