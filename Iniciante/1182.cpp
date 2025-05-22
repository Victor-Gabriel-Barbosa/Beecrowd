#include <bits/stdc++.h>
using namespace std;

int main() {
  int C;
  char T;
  cin >> C >> T;
  cin.ignore();

  vector<vector<double>> M(12, vector<double>(12));
  for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) cin >> M[i][j];
  cin.ignore();

  double res = 0;
  for (int i = 0; i < 12; i++) res += M[i][C];
  
  cout << fixed << setprecision(1) << ((toupper(T) == 'S') ? res : res / 12.0) << endl;

  return 0;
}