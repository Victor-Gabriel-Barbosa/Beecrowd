#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
  double nt[2];
  int ntVal = 0;

  do {
    double temp;
    cin >> temp;
    cin.ignore();

    if (temp < 0.0 || temp > 10.0) {
      cout << "nota invalida" << endl;
      continue;
    } else {
      ntVal++;
      nt[ntVal - 1] = temp;
    }
  } while (ntVal < 2);

  cout << fixed << setprecision(2);
  cout << "media = " << (nt[0] + nt[1]) / 2.0 << endl;

  return 0;
}