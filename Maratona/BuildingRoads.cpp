#include <bits/stdc++.h>
using namespace std;

// Busca em profundidade para marcar componentes conectados
void dfs(vector<int>& visitados, vector<vector<int>>& adj, int i, int V) {
  visitados[i] = V; // Marca o nó como visitado com o ID do componente
  for (int vizinho : adj[i]) if (visitados[vizinho] == 0) dfs(visitados, adj, vizinho, V);
}

int main() {
  int N, M; // N = número de cidades, M = número de estradas
  cin >> N >> M;

  vector<int> visitados(N + 1); // Armazena a qual componente cada cidade pertence
  vector<vector<int>> adj(N + 1); // Lista de adjacência representando as conexões

  // Constrói o grafo não-direcionado
  while (M--) {
    int A, B;
    cin >> A >> B;
    adj[A].push_back(B);
    adj[B].push_back(A);
  }

  // Identifica os componentes conectados
  int numComp = 0;
  for (int i = 1; i <= N; i++) {
    if (visitados[i] == 0) {
      numComp++; // Novo componente encontrado
      dfs(visitados, adj, i, numComp);
    }
  }

  // Imprime o número mínimo de estradas necessárias
  cout << numComp - 1 << endl;

  // Imprime quais cidades conectar para ligar todos os componentes
  if (numComp > 1) {
    vector<int> cidades(numComp + 1, 0); // Armazena uma cidade representante de cada componente
    for (int i = 1; i <= N; i++) cidades[visitados[i]] = i;

    // Conecta cada componente ao próximo
    for (int i = 1; i < numComp; i++) cout << cidades[i] << " " << cidades[i + 1] << endl;
  }

  return 0;
}