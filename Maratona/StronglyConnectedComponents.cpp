#include <bits/stdc++.h>
using namespace std;

// Implementação do algoritmo de Kosaraju para encontrar SCCs
class Kosaraju {
private:
  int N;                    // Número de vértices
  vector<vector<int>> adj;  // Lista de adjacência original
  vector<vector<int>> adjT; // Lista de adjacência transposta
  vector<bool> visitados;   // Rastreamento de visitas
  vector<int> ordem;        // Ordem de finalização da primeira DFS
  vector<int> componente;   // Armazena o SCC de cada vértice
  vector<vector<int>> SCCs; // Lista de SCCs

  // Primeira DFS para estabelecer a ordem de visitação
  void dfs1(int v) {
    visitados[v] = true;
    for (int u : adj[v]) if (!visitados[u]) dfs1(u);
    ordem.push_back(v); // Adiciona vértice na ordem inversa de finalização
  }

  // Segunda DFS para identificar componentes
  void dfs2(int v, int compAtual) {
    visitados[v] = true;
    componente[v] = compAtual;
    SCCs[compAtual].push_back(v);

    for (int u : adjT[v]) if (!visitados[u]) dfs2(u, compAtual);
  }

public:
  Kosaraju(int n) : N(n) {
    adj.resize(N);
    adjT.resize(N);
    componente.resize(N, -1);
  }

  // Adiciona uma aresta ao grafo
  void adicionarAresta(int a, int b) {
    adj[a].push_back(b);
    adjT[b].push_back(a); // Aresta reversa para o grafo transposto
  }

  // Encontra os componentes fortemente conectados
  vector<vector<int>> encontrarSCCs() {
    // Primeira passagem: DFS no grafo original
    visitados.assign(N, false);
    ordem.clear();

    for (int i = 0; i < N; i++) if (!visitados[i]) dfs1(i);

    // Segunda passagem: DFS no grafo transposto
    visitados.assign(N, false);
    SCCs.clear();

    // Processa vértices em ordem reversa de finalização
    for (int i = N - 1; i >= 0; i--) {
      int v = ordem[i];
      if (!visitados[v]) {
        SCCs.push_back(vector<int>());
        dfs2(v, SCCs.size() - 1);
      }
    }

    return SCCs;
  }
};

// Ordenação topológica dos SCCs
vector<vector<int>> ordenarSCCsTopologicamente(vector<vector<int>> &SCCs, int N, vector<vector<int>> &adj) {
  // Cria grafo condensado onde cada SCC é um nó
  int numSCCs = SCCs.size();
  vector<vector<int>> grafoSCC(numSCCs);
  vector<int> grauEntrada(numSCCs, 0);

  // Mapeia cada vértice para seu SCC
  vector<int> verticeParaSCC(N);
  for (int i = 0; i < numSCCs; i++) for (int v : SCCs[i]) verticeParaSCC[v] = i;

  // Cria arestas entre SCCs
  set<pair<int, int>> arestas;
  for (int u = 0; u < N; u++) {
    int sccU = verticeParaSCC[u];
    for (int v : adj[u]) {
      int sccV = verticeParaSCC[v];
      if (sccU != sccV && arestas.find({sccU, sccV}) == arestas.end()) {
        arestas.insert({sccU, sccV});
        grafoSCC[sccU].push_back(sccV);
        grauEntrada[sccV]++;
      }
    }
  }

  // Ordenação topológica usando BFS
  queue<int> fila;
  for (int i = 0; i < numSCCs; i++) if (grauEntrada[i] == 0) fila.push(i);

  vector<int> ordem;
  while (!fila.empty()) {
    int scc = fila.front();
    fila.pop();
    ordem.push_back(scc);

    for (int vizinho : grafoSCC[scc]) {
      grauEntrada[vizinho]--;
      if (grauEntrada[vizinho] == 0) fila.push(vizinho);
    }
  }

  // Reordena os SCCs conforme a ordem topológica
  vector<vector<int>> SCCsOrdenados;
  for (int idx : ordem) SCCsOrdenados.push_back(SCCs[idx]);

  return SCCsOrdenados;
}

int main() {
  int N, M;
  cin >> N >> M;

  Kosaraju kosaraju(N);
  vector<vector<int>> adj(N);

  // Lê as arestas
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    kosaraju.adicionarAresta(a, b);
    adj[a].push_back(b);
  }

  // Encontra os SCCs
  vector<vector<int>> SCCs = kosaraju.encontrarSCCs();

  // Ordena topologicamente
  vector<vector<int>> SCCsOrdenados = ordenarSCCsTopologicamente(SCCs, N, adj);

  // Imprime o resultado
  cout << SCCsOrdenados.size() << endl;
  for (auto &scc : SCCsOrdenados) {
    cout << scc.size();
    for (int v : scc) cout << " " << v;
    cout << endl;
  }

  return 0;
}