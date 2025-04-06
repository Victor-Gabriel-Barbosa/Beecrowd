#include <iostream>
using namespace std;

int main() {
  double I = 0.0, J = 1.0;

  int cont = 0;
  while (I <= 2.0) {
    cout << "I=" << I << " J=" << J << endl;
    cont++;
    if (cont == 3) {
      cont = 0;
      I += 0.2;
      J = I + 1.0;
    } else J += 1.0;
  }

  return 0;
}