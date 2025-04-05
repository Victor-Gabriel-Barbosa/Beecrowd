#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Algoritmo de Edmonds-Karp para encontrar o fluxo máximo
int edmondsKarp(vector<vector<int>> &grafo, int fonte, int sumidouro) {
  int vertices = grafo.size();
  int fluxoMaximo = 0;
  bool continua = true;

  // BFS para encontrar um caminho de aumento
  while (continua) {
    vector<int> pai(vertices, -1);
    queue<int> fila;
    fila.push(fonte);
    pai[fonte] = -2; // Marca a fonte como visitada

    while (!fila.empty() && pai[sumidouro] == -1) {
      int u = fila.front();
      fila.pop();

      for (int v = 0; v < vertices; ++v) {
        if (pai[v] == -1 && grafo[u][v] > 0) {
          pai[v] = u;
          fila.push(v);
        }
      }
    }

    // Se não foi encontrado caminho de aumento, terminou
    if (pai[sumidouro] == -1) {
      continua = false;
      continue;
    }

    // Encontra a capacidade mínima ao longo do caminho de aumento
    int fluxoCaminho = numeric_limits<int>::max();
    for (int v = sumidouro; v != fonte; v = pai[v]) {
      int u = pai[v];
      fluxoCaminho = min(fluxoCaminho, grafo[u][v]);
    }

    // Atualiza o grafo residual
    for (int v = sumidouro; v != fonte; v = pai[v]) {
      int u = pai[v];
      grafo[u][v] -= fluxoCaminho;
      grafo[v][u] += fluxoCaminho; // Adiciona aresta reversa para capacidade residual
    }

    fluxoMaximo += fluxoCaminho;
  }

  return fluxoMaximo;
}

int main() {
  int casosTeste;
  cin >> casosTeste;

  // Mapeia os tamanhos de camiseta para os índices
  map<string, int> tamanhoParaIndice = {{"XXL", 0}, {"XL", 1}, {"L", 2},
                                        {"M", 3},   {"S", 4},  {"XS", 5}};

  while (casosTeste--) {
    // N é o número total de camisetas
    // M é o número de voluntários
    // N/6 é o número de camisetas de cada tamanho
    int N, M;
    cin >> N >> M;

    int totalVertices = 1 + M + 6 + 1; // Fonte + Voluntários + Tamanhos + Sumidouro
    vector<vector<int>> grafo(totalVertices, vector<int>(totalVertices, 0));

    int fonte = 0;
    int primeiroVoluntario = 1;
    int primeiroTamanho = primeiroVoluntario + M;
    int sumidouro = primeiroTamanho + 6;

    // Conecta fonte aos voluntários com capacidade 1
    for (int i = 0; i < M; ++i) grafo[fonte][primeiroVoluntario + i] = 1;

    // Conecta cada voluntário aos seus tamanhos preferidos
    for (int i = 0; i < M; ++i) {
      string tamanho1, tamanho2;
      cin >> tamanho1 >> tamanho2;
      int indiceTamanho1 = tamanhoParaIndice[tamanho1];
      int indiceTamanho2 = tamanhoParaIndice[tamanho2];

      grafo[primeiroVoluntario + i][primeiroTamanho + indiceTamanho1] = 1;
      grafo[primeiroVoluntario + i][primeiroTamanho + indiceTamanho2] = 1;
    }

    // Conecta cada tamanho de camiseta ao sumidouro com capacidade N/6
    for (int i = 0; i < 6; ++i) grafo[primeiroTamanho + i][sumidouro] = N / 6;

    // Encontra fluxo máximo
    int fluxoMaximo = edmondsKarp(grafo, fonte, sumidouro);

    // Se todos os voluntários podem receber uma camiseta, fluxoMaximo deve ser igual a M
    if (fluxoMaximo == M) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}