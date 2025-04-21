#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &grupo, vector<vector<int>> &adj, int i, int V) {
  grupo[i] = V;
  for (int vizinho : adj[i]) if (grupo[vizinho] == 0) dfs(grupo, adj, vizinho, V);
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> grupo(N + 1);
  vector<vector<int>> adj(N + 1);

  while (M--) {
    int A, B;
    cin >> A >> B;
    adj[A].push_back(B);
    adj[B].push_back(A);
  }

  int numComp = 0;
  for (int i = 1; i <= N; i++) {
    if (grupo[i] == 0) {
      numComp++;
      dfs(grupo, adj, i, numComp);
    }
  }

  cout << numComp - 1 << endl;

  vector<int> pais;
  for (int i = 1; i <= N; i++) pais.push_back(grupo[i]);

  if (numComp > 1) {
    vector<int> cidades(numComp + 1, 0);
    for (int i = 1; i <= N; i++) cidades[grupo[i]] = i;

    for (int i = 1; i < numComp; i++) cout << cidades[i] << " " << cidades[i + 1] << endl;
  }

  return 0;
}