#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;

  while (cin >> N) {
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    vector<bool> visitado(N - 1, false);

    for (int i = 0; i < N - 1; i++) {
      int dif = abs(v[i] - v[i + 1]) - 1;
      if (dif >= 0 && dif < N - 1) visitado[dif] = true;
    }

    bool jolly = true;
    for (bool visita : visitado) {
      if (!visita) {
        jolly = false;
        break;
      }
    }

    cout << (jolly ? "Jolly" : "Not jolly") << endl;
  }

  return 0;
}