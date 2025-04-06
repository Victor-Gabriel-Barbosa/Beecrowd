#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double S = 0.0;

  for (int i = 1, j = 1; i <= 39; i += 2, j *= 2) S += (double) i / j;

  cout << fixed << setprecision(2) << S << endl;

  return 0;
}