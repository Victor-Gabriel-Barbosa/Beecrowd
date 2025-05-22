#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  while (cin >> N && N) {
    cin.ignore();

    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    cin.ignore();

    int picos = 0;
    for (int i = 0; i < N; i++) {
      int ant = (i == 0) ? N - 1 : i - 1;
      int prox = (i == N - 1) ? 0 : i + 1;

      if ((H[i] > H[ant] && H[i] > H[prox]) || (H[i] < H[ant] && H[i] < H[prox])) picos++;
    }
    cout << picos << endl;
  }

  return 0;
}