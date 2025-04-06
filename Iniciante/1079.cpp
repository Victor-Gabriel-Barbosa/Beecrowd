#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore();

  while (N--) {
    double A, B, C;
    cin >> A >> B >> C;
    cin.ignore();
    double media = (A * 2 + B * 3 + C * 5) / 10.0;
    cout << fixed << setprecision(1) << media << endl;
  }

  return 0;
}