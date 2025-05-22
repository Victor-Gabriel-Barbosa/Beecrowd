#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; 
  
  while (cin >> N && N) {
    vector<vector<int>> M(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
      M[i][0] = (i ? M[i - 1][0] * 2 : 1);
      for (int j = 1; j < N; j++) M[i][j] = M[i][j - 1] * 2;
    }

    int espaco = to_string(M[N - 1][N - 1]).size();
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << setw(espaco) << M[i][j];
        if (j < N - 1) cout << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}