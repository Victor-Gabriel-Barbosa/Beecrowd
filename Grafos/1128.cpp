#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Verifica se todos os nós são alcançáveis a partir do nó 'inicio'
bool buscaEmLargura(const vector<vector<int>> &grafo, int inicio, int n) {
  vector<bool> visitado(n + 1, false);
  queue<int> fila;

  fila.push(inicio);
  visitado[inicio] = true;

  while (!fila.empty()) {
    int atual = fila.front();
    fila.pop();

    for (int vizinho : grafo[atual]) {
      if (!visitado[vizinho]) {
        visitado[vizinho] = true;
        fila.push(vizinho);
      }
    }
  }

  // Verifica se todos os nós foram visitados
  for (int i = 1; i <= n; i++) if (!visitado[i]) return false;

  return true;
}

int main() {
  int n, m;

  while (cin >> n >> m && (n != 0 || m != 0)) {
    vector<vector<int>> grafo(n + 1);      // Grafo original
    vector<vector<int>> transposto(n + 1); // Grafo transposto

    for (int i = 0; i < m; i++) {
      int origem, destino, direcao;
      cin >> origem >> destino >> direcao;

      // Adiciona a rua ao grafo
      grafo[origem].push_back(destino);
      transposto[destino].push_back(origem); // Aresta inversa para o grafo transposto

      if (direcao == 2) { // Se a rua é de mão dupla
        grafo[destino].push_back(origem);
        transposto[origem].push_back(destino);
      }
    }

    // Verifica se o grafo é fortemente conexo
    // 1. Todos os nós são alcançáveis a partir do nó 1
    // 2. O nó 1 é alcançável a partir de todos os nós (verificando no grafo transposto)
    bool conectado = buscaEmLargura(grafo, 1, n) && buscaEmLargura(transposto, 1, n);

    cout << (conectado ? 1 : 0) << endl;
  }

  return 0;
}