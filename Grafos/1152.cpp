#include <bits/stdc++.h>
using namespace std;

// Estrutura para representar uma aresta do grafo
struct Aresta {
  int u, v, peso; // vértices u e v conectados pela aresta com peso
  // Operador para ordenar arestas por peso crescente
  bool operator<(const Aresta &outra) const { return peso < outra.peso; }
};

// Estrutura de dados Union-Find (Disjoint Set Union)
// Usada para detectar ciclos e unir componentes conexos
class UniaoBusca {
public:
  vector<int> pai, rank; // pai[i] = pai do nó i, rank[i] = altura da árvore

  // Construtor: inicializa cada nó como seu próprio pai
  UniaoBusca(int n) {
    pai.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++) pai[i] = i;
  }

  // Encontra o representante (raiz) do conjunto que contém x
  // Usa compressão de caminho para otimização
  int encontrar(int x) {
    if (pai[x] != x) pai[x] = encontrar(pai[x]);
    return pai[x];
  }

  // Une os conjuntos que contêm x e y
  // Retorna true se os conjuntos eram diferentes (união realizada)
  bool unir(int x, int y) {
    int px = encontrar(x), py = encontrar(y);
    if (px == py) // x e y já estão no mesmo conjunto
      return false;

    // União por rank: conecta árvore menor à maior
    if (rank[px] < rank[py]) pai[px] = py;
    else if (rank[px] > rank[py]) pai[py] = px;
    else {
      pai[py] = px;
      rank[px]++;
    }
    return true;
  }
};

int main() {
  int m, n; // m = número de junções, n = número de estradas

  // Lê casos de teste até encontrar m=n=0
  while (cin >> m >> n && (m != 0 || n != 0)) {
    vector<Aresta> arestas(n);
    long long custoTotal = 0; // custo total de todas as estradas

    // Lê todas as arestas e calcula custo total
    for (int i = 0; i < n; i++) {
      cin >> arestas[i].u >> arestas[i].v >> arestas[i].peso;
      custoTotal += arestas[i].peso;
    }

    // Ordena arestas por peso crescente (algoritmo de Kruskal)
    sort(arestas.begin(), arestas.end());

    UniaoBusca ub(m);
    long long custoAGM = 0; // custo da Árvore Geradora Mínima

    // Algoritmo de Kruskal: adiciona arestas que não formam ciclos
    for (const Aresta &a : arestas) 
      if (ub.unir(a.u, a.v)) custoAGM += a.peso;

    // A economia é a diferença entre custo total e custo da AGM
    cout << custoTotal - custoAGM << endl;
  }

  return 0;
}
