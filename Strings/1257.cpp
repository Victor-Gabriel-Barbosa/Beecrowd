#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  while (N--) {
    int L, T = 0;
    string palavra;
    cin >> L;

    for (int i = 0; i < L; i++) {
      cin >> palavra;
      for (size_t j = 0; j < palavra.size(); j++) T += palavra[j] - 'A' + i + j;
    }

    cout << T << endl;
  }
}