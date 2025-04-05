#include <iostream>
using namespace std;

const int MAX_V = 10000;

class GrafoLabirinto {
private:
  int vertices;
  int arestas;
  int ctVisita;
  int passosTomados;
  int visitados[MAX_V];
  int rede[100][100];

public:
  GrafoLabirinto() : ctVisita(0), passosTomados(0) {}
  void inicializaGrafo(int v, int a) {
    vertices = v;
    arestas = a;
    passosTomados = 0;
    for (int i = 0; i < vertices; i++) for (int j = 0; j < vertices; j++) rede[i][j] = 0;
  }

  void adicionaConexao(int origem, int destino) {
    rede[origem][destino] = 1;
    rede[destino][origem] = 1; 
  }

  void resetaVisitados() {
    for (int i = 0; i < vertices; i++) visitados[i] = -1;
  }

  void exploraAPartirDe(int noInicial) {
    resetaVisitados();
    percorreGrafo(noInicial);
  }

  void percorreGrafo(int no) {
    visitados[no] = ctVisita++;
    for (int vizinho = 0; vizinho < vertices; vizinho++) {
      if (rede[no][vizinho] == 1 && visitados[vizinho] == -1) {
        passosTomados++;
        percorreGrafo(vizinho);
      }
    }
  }

  int contaTotalPassos() {
    return passosTomados * 2;
  }
};

int main() {
  int casosTeste, numVertices, numArestas;
  int verticeInicial, origem, destino;
  cin >> casosTeste;
  while (casosTeste--) {
    cin >> verticeInicial;
    cin >> numVertices;
    GrafoLabirinto explorador;
    explorador.inicializaGrafo(numVertices, 0);
    cin >> numArestas;
    for (int i = 0; i < numArestas; i++) {
      cin >> origem >> destino;
      explorador.adicionaConexao(origem, destino);
    }
    explorador.exploraAPartirDe(verticeInicial);
    cout << explorador.contaTotalPassos() << endl;
  }
  return 0;
}