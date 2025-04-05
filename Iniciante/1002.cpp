#include <iostream>
#include <iomanip>
using namespace std;

#define PI 3.14159
#define area(r) (PI * (r) * (r))

int main() {
  double raio;

  cin >> raio;
  cout << fixed << setprecision(4);
  cout << "A=" << area(raio) << endl;

  return 0;
}