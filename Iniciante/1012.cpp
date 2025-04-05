#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define PI 3.14159

int main() {
  double a, b, c;
  
  cin >> a >> b >> c;
  cout << fixed << setprecision(3);
  cout << "TRIANGULO: " << (a * c) / 2 << endl;
  cout << "CIRCULO: " << PI * pow(c, 2) << endl;
  cout << "TRAPEZIO: " << (a + b) * c / 2 << endl;
  cout << "QUADRADO: " << pow(b, 2) << endl;
  cout << "RETANGULO: " << a * b << endl;

  return 0;
}