#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  while (cin >> N && N != 0) {
    vector<int> pai(N, -1);
    vector<ll> distRaiz(N, 0);
    vector<vector<int>> adj(N);
    vector<int> prf(N, 0);

    // Constrói a árvore
    for (int i = 1; i < N; i++) {
      int A;
      ll L;
      cin >> A >> L;
      pai[i] = A;
      distRaiz[i] = distRaiz[A] + L;
      adj[A].push_back(i);
    }

    // Calcula as profundidades
    function<void(int, int)> dfs = [&](int u, int d) {
      prf[u] = d;
      for (int v : adj[u]) dfs(v, d + 1);
    };
    dfs(0, 0);

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
      int S, T;
      cin >> S >> T;

      // LCA otimizado - eleva nós para mesma profundidade primeiro
      int u = S, v = T;
      if (prf[u] < prf[v]) swap(u, v);

      // Sobe o nó mais profundo até ficarem na mesma profundidade
      while (prf[u] > prf[v]) u = pai[u];

      // Sobe ambos simultaneamente até encontrar o LCA
      while (u != v) {
        u = pai[u];
        v = pai[v];
      }

      int lca = u; // LCA encontrado

      // Calcula distância usando a mesma fórmula
      ll dist = distRaiz[S] + distRaiz[T] - 2 * distRaiz[lca];

      cout << dist;
      if (q < Q - 1) cout << " ";
    }
    cout << endl;
  }

  return 0;
}