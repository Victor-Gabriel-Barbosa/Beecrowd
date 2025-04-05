#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define PI 3.14159

int main() {
  double a;

  cin >> a;
  cout << fixed << setprecision(3);
  cout << "VOLUME = " << (((double) 4 / 3) * PI * pow(a, 3)) << endl;
  
  return 0;
}