#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int a1, b1, a2, b2;
  double c1, c2;

  cin >> a1 >> b1 >> c1;
  cin >> a2 >> b2 >> c2;
  cout << fixed << setprecision(2);
  cout << "VALOR A PAGAR: R$ " << (b1 * c1 + b2 * c1) << endl;
  
  return 0;
}