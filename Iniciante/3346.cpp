#include <bits/stdc++.h>
using namespace std;

int main() {
  double F1, F2;
  cin >> F1 >> F2;
  
  cout << fixed << setprecision(6) << ((1 + F1/100.0) * (1 + F2/100.0) - 1) * 100.0 << endl;
  
  return 0;
}