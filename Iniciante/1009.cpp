#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  string nome;
  double a, b;

  cin >> nome >> a >> b;
  cout << fixed << setprecision(2);
  cout << "TOTAL = R$ " << a + b * 0.15 << endl;

  return 0;
}