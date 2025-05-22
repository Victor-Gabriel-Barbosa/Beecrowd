#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; 
  
  while (cin >> N && N) {
    vector<vector<int>> M(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
      M[i][i] = 1;
      for (int j = i + 1; j < N; j++) M[j][i] = M[j - 1][i] + 1;
      for (int j = i - 1; j >= 0; j--) M[j][i] = M[j + 1][i] + 1;
    }
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << setw(3) << M[i][j];
        if (j < N - 1) cout << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}