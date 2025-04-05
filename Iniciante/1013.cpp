#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define PI 3.14159

int main() {
  int a, b, c;

  cin >> a >> b >> c;
  cout << fixed << setprecision(3);
  cout << max(a, max(b, c)) << " eh o maior" << endl;

  return 0;
}