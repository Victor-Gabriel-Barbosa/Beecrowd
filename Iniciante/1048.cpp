#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double SB, SN, RJ;
  
  cin >> SB;
  if (SB <= 400.00) {
    SN = SB * 1.15;
    RJ = SN - SB;
  } else if (SB <= 800.00) {
    SN = SB * 1.12;
    RJ = SN - SB;
  } else if (SB <= 1200.00) {
    SN = SB * 1.10;
    RJ = SN - SB;
  } else if (SB <= 2000.00) {
    SN = SB * 1.07;
    RJ = SN - SB;
  } else {
    SN = SB * 1.04;
    RJ = SN - SB;
  }

  cout << fixed << setprecision(2);
  cout << "Novo salario: " << SN << endl;
  cout << "Reajuste ganho: " << RJ << endl;
  cout << fixed << setprecision(0);
  cout << "Em percentual: " << ((SN / SB) - 1) * 100 << " %" << endl;
  
  return 0;
}