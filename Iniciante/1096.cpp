#include <iostream>
using namespace std;

int main() {
  int I = 1, J = 7;

  while (I <= 9) {
    for (int i = 0; i < 3; i++) {
      cout << "I=" << I << " J=" << J << endl;
      J--;
    }
    I += 2;
    J += 3;
  }

  return 0;
}