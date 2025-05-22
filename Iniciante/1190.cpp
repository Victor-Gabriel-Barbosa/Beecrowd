#include <bits/stdc++.h>
using namespace std;

int main() {
  char op;
  vector<vector<double>> M(12, vector<double>(12));

  cin >> op;
  cin.ignore();

  for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) cin >> M[i][j];
  cin.ignore();

  double res = 0;
  for (int i = 1; i < 6; i++) for (int j = 12 - i; j < 12; j++) res += M[i][j];
  for (int i = 6; i < 11; i++) for (int j = i + 1; j < 12; j++) res += M[i][j];

  cout << fixed << setprecision(1) << ((toupper(op) == 'S') ? res : res / 30.0) << endl;

  return 0;
}