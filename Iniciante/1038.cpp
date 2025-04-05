#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main() {
  double c, q;

  cin >> c >> q;
  map<int, double> m = {{1, 4.00}, {2, 4.50}, {3, 5.00}, {4, 2.00}, {5, 1.50}};
  cout << "Total: R$ " << fixed << setprecision(2) << m[c] * q << endl;

  return 0;
}