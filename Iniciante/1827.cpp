#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; 
  
  while (cin >> N && N) {
    vector<vector<int>> M(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
      M[i][i] = 2;
      M[i][N - 1 - i] = 3;
    }

    for (int i = N / 3; i < N - N / 3; i++) {
      for (int j = N / 3; j < N - N / 3; j++) M[i][j] = 1;
    }

    M[N / 2][N / 2] = 4;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << M[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}