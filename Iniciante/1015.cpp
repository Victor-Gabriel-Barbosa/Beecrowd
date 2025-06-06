#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define PI 3.14159

int main() {
  double x1, x2, y1, y2;

  cin >> x1 >> y1 >> x2 >> y2;
  cout << fixed << setprecision(4);
  cout << sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) << endl;

  return 0;
}