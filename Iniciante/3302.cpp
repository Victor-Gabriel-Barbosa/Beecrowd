using namespace std;
#include <bits/stdc++.h>

int main() {
  int N;
  cin >> N;
  int V[N];

  for (int i = 0; i < N; i++) cin >> V[i];

  for (int i = 0; i < N; i++) cout << "resposta " << i + 1 << ": " << V[i] << endl;

  return 0;
}