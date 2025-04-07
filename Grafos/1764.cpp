#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Estrutura para representar uma aresta
struct Aresta {
  int origem, destino, peso;
};

// Estrutura para representar um grafo
class Grafo {
private:
  int V;                  // Número de vértices
  vector<Aresta> arestas; // Lista de arestas

public:
  Grafo(int V) { 
    this->V = V; 
  }

  // Adiciona uma aresta não direcionada ao grafo
  void adicionarAresta(int origem, int destino, int peso) {
    arestas.push_back((Aresta){origem, destino, peso});
    arestas.push_back((Aresta){destino, origem, peso});
  }

  // Encontra a MST usando o algoritmo de Borůvka
  int boruvkaMST() {
    int pesoTotal = 0;

    // Armazena qual componente cada vértice pertence
    vector<int> pai(V);

    // Armazena o índice da aresta mais leve que conecta dois componentes
    vector<int> maisBarato(V, -1);

    // Inicialmente, cada vértice está em seu próprio componente
    for (int i = 0; i < V; i++) pai[i] = i;

    // Número de componentes iniciais é igual ao número de vértices
    int numComp = V;

    // Continua até que todos os vértices estejam em um único componente
    while (numComp > 1) {
      // Inicializa maisBarato para cada componente
      fill(maisBarato.begin(), maisBarato.end(), -1);

      // Para cada aresta, verifica se é a mais leve para conectar dois componentes
      for (size_t i = 0; i < arestas.size(); i++) {
        int conj1 = encontrarRaiz(pai, arestas[i].origem);
        int conj2 = encontrarRaiz(pai, arestas[i].destino);

        // Se os vértices estão em componentes diferentes
        if (conj1 != conj2) {
          // Verifica se a aresta é a mais leve para o componente conj1
          if (maisBarato[conj1] == -1 || arestas[i].peso < arestas[maisBarato[conj1]].peso) maisBarato[conj1] = i;

          // Verifica se a aresta é a mais leve para o componente conj2
          if (maisBarato[conj2] == -1 || arestas[i].peso < arestas[maisBarato[conj2]].peso) maisBarato[conj2] = i;
        }
      }

      // Adiciona as arestas mais leves à MST
      for (int i = 0; i < V; i++) {
        // Se não há aresta para o componente, ignora
        if (maisBarato[i] == -1) continue;

        int conj1 = encontrarRaiz(pai, arestas[maisBarato[i]].origem);
        int conj2 = encontrarRaiz(pai, arestas[maisBarato[i]].destino);

        if (conj1 != conj2) {
          // Adiciona o peso da aresta ao total
          pesoTotal += arestas[maisBarato[i]].peso;

          // Une os dois componentes
          unirConjuntos(pai, conj1, conj2);

          // Decrementa o número de componentes
          numComp--;
        }
      }
    }

    return pesoTotal;
  }

  // Encontra o representante (ou raiz) de um conjunto
  int encontrarRaiz(vector<int> &pai, int i) {
    if (pai[i] != i) pai[i] = encontrarRaiz(pai, pai[i]); // Compressão de caminho
    return pai[i];
  }

  // Une dois conjuntos diferentes
  void unirConjuntos(vector<int> &pai, int x, int y) {
    int raizX = encontrarRaiz(pai, x);
    int raizY = encontrarRaiz(pai, y);
    if (raizX != raizY) pai[raizY] = raizX;
  }
};

int main() {
  int M, N; // M = número de cidades, N = número de caminhos

  do {
    cin >> M >> N;

    if (M == 0 && N == 0) continue; 

    // Cria o grafo com M vértices (cidades)
    Grafo cidades(M);

    // Leitura das arestas
    for (int i = 0; i < N; i++) {
      int X, Y, Z; // X e Y são as cidades, Z é a distância
      cin >> X >> Y >> Z;
      cidades.adicionarAresta(X, Y, Z);
    }

    // Calcula e imprime o resultado
    int resultado = cidades.boruvkaMST();
    cout << resultado << endl;
  } while (M != 0 || N != 0);

  return 0;
}