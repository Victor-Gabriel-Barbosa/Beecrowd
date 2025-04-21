using namespace std;
#include <bits/stdc++.h>

int main() {
  int N, Q;
  cin >> N >> Q;

  int V[N];
  for (int i = 0; i < N; i++) cin >> V[i];

  while (Q--) {
    int tipo, A, B, V1;
    cin >> tipo >> A >> B;
    if (tipo == 1) {
      cin >> V1;
      for (int i = A - 1; i < B; i++) V[i] += V1;
    } else {
      int mdc = V[A - 1];
      for (int i = A; i < B; i++) mdc = __gcd(mdc, V[i]);
      cout << mdc << endl;
    }
  }

  return 0;
}