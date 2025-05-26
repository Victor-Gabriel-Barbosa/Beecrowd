#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;

  while (cin >> A && A && cin >> B && B && cin >> C && C) {
    cin.ignore();
    cout << (int)sqrt((A * B * 100) / C) << endl;
  }

  return 0;
} 