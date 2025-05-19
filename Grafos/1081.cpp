#include <bits/stdc++.h>
using namespace std;

// Função DFS que imprime a hierarquia
void dfs(int v, int nivel, vector<vector<int>>& grafo, vector<bool>& visitado) {
  visitado[v] = true;

  // Ordena os vizinhos para garantir a ordem crescente
  sort(grafo[v].begin(), grafo[v].end());

  for (int vizinho : grafo[v]) {
    // Indentação (2 espaços por nível)
    for (int i = 0; i < nivel * 2; i++) cout << " ";

    cout << v << "-" << vizinho;

    if (!visitado[vizinho]) {
      cout << " pathR(G," << vizinho << ")" << endl;
      dfs(vizinho, nivel + 1, grafo, visitado);
    } else cout << endl;
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> grafo;
  vector<bool> visitado;

  for (int caso = 1; caso <= n; caso++) {
    int v, e;
    cin >> v >> e;

    // Inicializa o grafo e vetor de visitados
    grafo.assign(v, vector<int>());
    visitado.assign(v, false);

    // Leitura das arestas
    for (int i = 0; i < e; i++) {
      int a, b;
      cin >> a >> b;
      grafo[a].push_back(b);
    }

    cout << "Caso " << caso << ":" << endl;

    // Realiza DFS para cada vértice não visitado
    for (int i = 0; i < v; i++) {
      if (!visitado[i]) {
        // Se existem arestas saindo deste vértice
        if (!grafo[i].empty()) {
          dfs(i, 1, grafo, visitado);
          cout << endl;
        }
      }
    }
  }

  return 0;
}