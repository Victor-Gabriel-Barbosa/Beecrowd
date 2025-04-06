#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Verifica se a string a é substring contígua de b
bool ehSubstring(const string &a, const string &b) {
  return b.find(a) != string::npos;
}

// Calcula o tamanho da maior sequência possível
int maiorSequencia(vector<string> &fotos) {
  int n = fotos.size();
  vector<vector<int>> grafo(n);

  // Adiciona uma aresta de i para j se a foto i pode crescer para a foto j
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && ehSubstring(fotos[i], fotos[j])) grafo[i].push_back(j);
    }
  }

  // Programação dinâmica para encontrar o caminho mais longo
  vector<int> memoria(n, 0);
  vector<bool> visitado(n, false);

  // Função recursiva com memorização para encontrar o caminho mais longo
  function<int(int)> buscarMaiorCaminho = [&](int vertice) {
    if (visitado[vertice]) return memoria[vertice];

    visitado[vertice] = true;
    memoria[vertice] = 1; // Inicializa com 1 (a própria foto)

    for (int proximo : grafo[vertice]) memoria[vertice] = max(memoria[vertice], 1 + buscarMaiorCaminho(proximo));

    return memoria[vertice];
  };

  // Tenta iniciar o caminho em cada vértice e mantém o melhor resultado
  int resultado = 0;
  for (int i = 0; i < n; i++) resultado = max(resultado, buscarMaiorCaminho(i));

  return resultado;
}

int main() {
  int n;

  // Processa cada caso de teste até encontrar um zero
  while (cin >> n && n != 0) {
    vector<string> fotos(n);
    for (int i = 0; i < n; i++) cin >> fotos[i];
    cout << maiorSequencia(fotos) << endl;
  }

  return 0;
}