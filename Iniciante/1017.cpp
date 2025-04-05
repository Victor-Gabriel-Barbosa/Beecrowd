#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int h, v;

  cin >> h >> v;
  cout << fixed << setprecision(3);
  cout << (double) (v * h) / 12 << endl;

  return 0;
}