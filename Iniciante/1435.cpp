#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; 
  
  while (cin >> N && N) {
    vector<vector<int>> M(N, vector<int>(N, 1));

    int temp = 2;
    for (int k = 0; k < N / 2; k++) {
      for (int i = k + 1; i < N - 1 - k; i++) {
        for (int j = k + 1; j < N - 1 - k; j++) {
          M[i][j] = temp;
        }
      }
      temp++;
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