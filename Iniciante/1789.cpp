#include <bits/stdc++.h>
using namespace std;

int main() {
  int L;

  while (cin >> L) {
    cin.ignore();
    
    int V = INT_MIN, lesma;
    for (int i = 0; i < L; i++) {
      cin >> lesma;
      cin.ignore();
      V = max(V, lesma);
    }

    cout << (V < 10 ? "1" : V < 20 ? "2" : "3") << endl;
  }

  return 0;
}