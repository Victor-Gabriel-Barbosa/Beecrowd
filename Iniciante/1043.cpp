#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  double a, b, c;
  
  cin >> a >> b >> c;
  vector<double> v = {a, b, c};
  sort(v.begin(), v.end());

  if (v[0] + v[1] > v[2]) cout << "Perimetro = " << fixed << setprecision(1) << (double) a + b + c << endl;
  else cout << "Area = " << fixed << setprecision(1) << (a + b) * (double) c / 2 << endl;

  return 0;
}