#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Estrutura para representar uma aresta (caminho entre cidades)
struct Aresta {
  int origem, destino, peso;
};

// Classe para representar o grafo (cidades e caminhos)
class Grafo {
private:
  int numVertices;        // Número de vértices (cidades)
  vector<Aresta> arestas; // Lista de arestas (caminhos)

public:
  // Construtor do grafo
  Grafo(int numVertices) { 
    this->numVertices = numVertices; 
  }

  // Adiciona uma aresta não direcionada ao grafo
  void adicionarAresta(int origem, int destino, int peso) {
    arestas.push_back((Aresta){origem, destino, peso});
    arestas.push_back((Aresta){destino, origem, peso});
  }

  // Encontra a MST usando o algoritmo de Borůvka
  int boruvkaMST() {
    int pesoTotal = 0;

    // Armazena a qual componente cada vértice pertence
    vector<int> pai(numVertices);

    // Armazena o índice da aresta mais leve que conecta dois componentes
    vector<int> maisBarato(numVertices);

    // Inicialmente, cada vértice está em seu próprio componente
    for (int i = 0; i < numVertices; i++) pai[i] = i;

    // Número de componentes iniciais é igual ao número de vértices
    int numComponentes = numVertices;

    // Continua até que todos os vértices estejam em um único componente
    while (numComponentes > 1) {
      // Inicializa maisBarato para cada componente (como -1)
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
      for (int i = 0; i < numVertices; i++) {
        // Ignora se não há aresta para o componente
        if (maisBarato[i] == -1) continue;

        int conj1 = encontrarRaiz(pai, arestas[maisBarato[i]].origem);
        int conj2 = encontrarRaiz(pai, arestas[maisBarato[i]].destino);

        // Une os componentes se os vértices estão em componentes diferentes
        if (conj1 != conj2) {
          // Adiciona o peso da aresta ao total
          pesoTotal += arestas[maisBarato[i]].peso;

          // Une os dois componentes
          unirConjuntos(pai, conj1, conj2);

          // Decrementa o número de componentes
          numComponentes--;
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
  int numCidades, numCaminhos;

  do {
    cin >> numCidades >> numCaminhos;

    if (numCidades == 0 && numCaminhos == 0) continue; 

    // Cria o grafo com o número de cidades (vértices)
    Grafo cidades(numCidades);

    // Adiciona as arestas (caminhos) ao grafo
    for (int i = 0; i < numCaminhos; i++) {
      int cidade1, cidade2, distancia;
      cin >> cidade1 >> cidade2 >> distancia;
      cidades.adicionarAresta(cidade1, cidade2, distancia);
    }

    // Calcula e imprime o peso total da MST
    cout << cidades.boruvkaMST() << endl;
  } while (numCidades != 0 || numCaminhos != 0);

  return 0;
}