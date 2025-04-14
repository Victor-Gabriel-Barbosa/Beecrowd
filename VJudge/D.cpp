#include <bits/stdc++.h>
using namespace std;

int main() {
  long long I, J;

  while (cin >> I >> J) {
    int contMax = 1;
    for (long long k = min(I, J); k <= max(I, J); k++) {
      int contTemp = 1;
      for (long long n = k; n != 1; n = (n % 2 ? 3 * n + 1 : n / 2)) contTemp++;

      contMax = max(contMax, contTemp);
    }

    cout << I << " " << J << " " << contMax << endl;
  }


  return 0;
}