#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double salario, imposto = 0;

  cin >> salario;
  if (salario <= 2000) cout << "Isento" << endl;
  else {
    if (salario <= 3000) imposto = (salario - 2000) * 0.08;
    else if (salario <= 4500) imposto = 80 + (salario - 3000) * 0.18;
    else imposto = 80 + 270 + (salario - 4500) * 0.28;
    cout << "R$ " << fixed << setprecision(2) << imposto << endl;
  }
  
  return 0;
}