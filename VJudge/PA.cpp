#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, t;

  cin >> t;

  while (t--) {
    cin >> n >> m;
    cout << (m * n) - ((n * (n + 1)) / 2) << endl;
  }

  return 0;
}