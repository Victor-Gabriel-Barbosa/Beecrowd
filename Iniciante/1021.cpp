#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double valorMonetario = 0.0;
  cin >> valorMonetario;

  cout << "NOTAS:" << endl;

  int valorEmCentavos = static_cast<int>(valorMonetario * 100 + 0.5);

  int notasDe100 = valorEmCentavos / 10000;
  valorEmCentavos %= 10000;
  cout << notasDe100 << " nota(s) de R$ 100.00" << endl;

  int notasDe50 = valorEmCentavos / 5000;
  valorEmCentavos %= 5000;
  cout << notasDe50 << " nota(s) de R$ 50.00" << endl;

  int notasDe20 = valorEmCentavos / 2000;
  valorEmCentavos %= 2000;
  cout << notasDe20 << " nota(s) de R$ 20.00" << endl;

  int notasDe10 = valorEmCentavos / 1000;
  valorEmCentavos %= 1000;
  cout << notasDe10 << " nota(s) de R$ 10.00" << endl;

  int notasDe5 = valorEmCentavos / 500;
  valorEmCentavos %= 500;
  cout << notasDe5 << " nota(s) de R$ 5.00" << endl;

  int notasDe2 = valorEmCentavos / 200;
  valorEmCentavos %= 200;
  cout << notasDe2 << " nota(s) de R$ 2.00" << endl;

  cout << "MOEDAS:" << endl;

  int moedasDe1 = valorEmCentavos / 100;
  valorEmCentavos %= 100;
  cout << moedasDe1 << " moeda(s) de R$ 1.00" << endl;

  int moedasDe050 = valorEmCentavos / 50;
  valorEmCentavos %= 50;
  cout << moedasDe050 << " moeda(s) de R$ 0.50" << endl;

  int moedasDe025 = valorEmCentavos / 25;
  valorEmCentavos %= 25;
  cout << moedasDe025 << " moeda(s) de R$ 0.25" << endl;

  int moedasDe010 = valorEmCentavos / 10;
  valorEmCentavos %= 10;
  cout << moedasDe010 << " moeda(s) de R$ 0.10" << endl;

  int moedasDe005 = valorEmCentavos / 5;
  valorEmCentavos %= 5;
  cout << moedasDe005 << " moeda(s) de R$ 0.05" << endl;

  int moedasDe001 = valorEmCentavos;
  cout << moedasDe001 << " moeda(s) de R$ 0.01" << endl;

  return 0;
}