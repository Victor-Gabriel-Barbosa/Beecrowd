#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double A[100];
  for (int i = 0; i < 100; i++) cin >> A[i];

  cout << fixed << setprecision(1);
  for (int i = 0; i < 100; i++) if (A[i] <= 10.0) cout << "A[" << i << "] = " << A[i] << endl;

  return 0;
}