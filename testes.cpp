#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<pair<int, int>> grafo;
  int n, m;
  
  for (int i = 0; i < 5; i++) {
    cin >> n >> m;
    grafo.push_back({n, m});
  }

  for (auto [n, m] : grafo) cout << n << " " << m << endl;
}
