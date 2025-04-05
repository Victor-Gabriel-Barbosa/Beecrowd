#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Estrutura para representar uma aresta no grafo
struct Aresta {
  int destino;
  int custo;
  Aresta(int d, int c) : destino(d), custo(c) {}
};

// Estrutura para o algoritmo de Dijkstra
struct Nodo {
  int cidade;
  int custo;
  Nodo(int c, int p) : cidade(c), custo(p) {}
  
  // Operador de comparação para a fila de prioridade
  bool operator>(const Nodo& outro) const {
    return custo > outro.custo;
  }
};

int custoMinimo(vector<vector<Aresta>>& grafo, int numCidades, int numRotas, int cidadeInicial) {
  // Vetor para armazenar o custo mínimo para chegar a cada cidade
  vector<int> distancia(numCidades, INT_MAX);
  
  // Fila de prioridade para o algoritmo de Dijkstra
  priority_queue<Nodo, vector<Nodo>, greater<Nodo>> filaPrioridade;
  
  // Inicia com a cidade onde o veículo foi consertado
  distancia[cidadeInicial] = 0;
  filaPrioridade.push(Nodo(cidadeInicial, 0));
  
  while (!filaPrioridade.empty()) {
    Nodo atual = filaPrioridade.top();
    filaPrioridade.pop();
    
    int cidade = atual.cidade;
    int custo = atual.custo;
    
    // Se o custo atual é maior que o já registrado, ignora
    if (custo > distancia[cidade]) continue;
    
    // Se chegou a uma cidade da rota de serviço
    if (cidade < numRotas) {
      // Calcula o custo para chegar ao destino seguindo a rota de serviço
      int custoServico = 0;
      for (int i = cidade; i < numRotas - 1; i++) {
        // Encontra a aresta entre i e i+1
        for (const Aresta& a : grafo[i]) {
          if (a.destino == i + 1) {
            custoServico += a.custo;
            break;
          }
        }
      }
      
      // Atualiza o custo para o destino se for menor
      if (distancia[cidade] + custoServico < distancia[numRotas - 1]) distancia[numRotas - 1] = distancia[cidade] + custoServico;
      
      // Não precisa explorar outras rotas a partir desta cidade
      continue;
    }
    
    // Explora todas as arestas a partir da cidade atual
    for (const Aresta& a : grafo[cidade]) {
      int proxCidade = a.destino;
      int proxCusto = custo + a.custo;
      
      if (proxCusto < distancia[proxCidade]) {
        distancia[proxCidade] = proxCusto;
        filaPrioridade.push(Nodo(proxCidade, proxCusto));
      }
    }
  }
  
  return distancia[numRotas - 1];
}

int main() {
  int numCidades, numEstradas, numRotas, cidadeInicial;
  bool continuar = true;
  
  while (continuar) {
    cin >> numCidades >> numEstradas >> numRotas >> cidadeInicial;
    
    // Para quando todos os valores são zero
    if (numCidades == 0 && numEstradas == 0 && numRotas == 0 && cidadeInicial == 0) {
      continuar = false;
      continue;
    } 

    // Inicializa o grafo
    vector<vector<Aresta>> grafo(numCidades);
    
    // Lê as estradas
    for (int i = 0; i < numEstradas; i++) {
      int origem, destino, peso;
      cin >> origem >> destino >> peso;
      
      // Adiciona aresta nos dois sentidos (mão dupla)
      grafo[origem].push_back(Aresta(destino, peso));
      grafo[destino].push_back(Aresta(origem, peso));
    }
    
    // Calcula e imprime o resultado
    cout << custoMinimo(grafo, numCidades, numRotas, cidadeInicial) << endl;
  }
  
  return 0;
}