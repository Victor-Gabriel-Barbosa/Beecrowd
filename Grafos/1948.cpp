#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Verifica se uma string é um número inteiro positivo
bool ehInteiroPositivo(const string &str) {
  if (str.empty()) return false;
  for (char caractere : str) if (!isdigit(caractere)) return false;
  return true;
}

// Verifica se um nome de variável é válido
bool ehNomeDeVariavelValido(const string &str) {
  if (str.empty() || str.size() > 8) return false;
  for (char caractere : str) if (!islower(caractere)) return false;
  return true;
}

// Verifica se é possível colorir o grafo com no máximo 2 cores usando coloração gulosa
bool podeColorir(const vector<vector<int>> &grafo, int numVariaveis) {
  vector<int> cor(numVariaveis, -1); // -1 significa sem cor

  for (int nodo = 0; nodo < numVariaveis; nodo++) {
    // Ignora nós que já foram coloridos
    if (cor[nodo] != -1) continue;

    // Tenta colorir nó usando BFS
    queue<int> fila;
    fila.push(nodo);
    cor[nodo] = 0; // colore com a primeira cor (0)

    while (!fila.empty()) {
      int atual = fila.front();
      fila.pop();

      // Para cada vizinho
      for (int vizinho : grafo[atual]) {
        // Se o vizinho já tem a mesma cor que o nó atual, um conflito foi encontrado
        if (cor[vizinho] == cor[atual]) return false;

        // Se o vizinho ainda não foi colorido
        if (cor[vizinho] == -1) {
          // Colore ele com a cor oposta
          cor[vizinho] = 1 - cor[atual];
          fila.push(vizinho);
        }
      }
    }
  }

  return true;
}

int main() {
  string linha;
  unordered_map<string, int> indiceVar; // Mapeia nomes de variáveis para índices
  unordered_map<string, bool> variaveisDefinidas; // Mapeia variáveis para seu estado de definição
  vector<pair<string, string>> dependencias; // Armazena dependências entre variáveis

  int contadorVar = 0;

  // Lê cada uma das instruções do programa
  while (getline(cin, linha)) {
    if (linha.empty()) continue;

    istringstream iss(linha);
    string destino, token, operando1, operando2;

    // Lê o destino
    iss >> destino;

    // Verifica se o nome da variável destino é válido
    if (!ehNomeDeVariavelValido(destino)) {
      cout << "Compilation Error" << endl;
      return 0;
    }

    // Verifica se a variável já foi definida antes
    if (variaveisDefinidas.find(destino) != variaveisDefinidas.end()) {
      cout << "Compilation Error" << endl;
      return 0;
    }

    // Lê o token de atribuição ':='
    iss >> token;
    if (token != ":=") {
      cout << "Compilation Error" << endl;
      return 0;
    }

    // Lê o primeiro operando
    iss >> operando1;

    // Verificar se o primeiro operando é válido
    if (!ehInteiroPositivo(operando1) &&
        (!ehNomeDeVariavelValido(operando1) ||
         variaveisDefinidas.find(operando1) == variaveisDefinidas.end())) {
      cout << "Compilation Error" << endl;
      return 0;
    }

    // Adiciona variável destino ao mapa de índices se ainda não estiver lá
    if (indiceVar.find(destino) == indiceVar.end()) indiceVar[destino] = contadorVar++;

    // Verifica se ainda tem mais tokens (caso de soma)
    string mais;
    if (iss >> mais) {
      if (mais != "+") {
        cout << "Compilation Error" << endl;
        return 0;
      }

      // Lê o segundo operando
      iss >> operando2;

      // Verifica se o segundo operando é válido
      if (!ehInteiroPositivo(operando2) &&
          (!ehNomeDeVariavelValido(operando2) ||
           variaveisDefinidas.find(operando2) == variaveisDefinidas.end())) {
        cout << "Compilation Error" << endl;
        return 0;
      }

      // Registra dependências para variáveis (não para constantes)
      if (!ehInteiroPositivo(operando1)) dependencias.push_back({destino, operando1});
      if (!ehInteiroPositivo(operando2)) dependencias.push_back({destino, operando2});
    } else if (!ehInteiroPositivo(operando1)) dependencias.push_back({destino, operando1});

    // Marca a variável destino como definida
    variaveisDefinidas[destino] = true;
  }

  // Constrói grafo de interferência baseado em dependências
  vector<vector<int>> grafoInterferencia(contadorVar);

  // Cria conjunto de variáveis vivas em cada ponto
  vector<set<string>> varsVivas(dependencias.size() + 1);

  // Análise de vivacidade retrógrada
  for (int i = dependencias.size() - 1; i >= 0; i--) {
    // Variáveis vivas neste ponto são as mesmas do próximo ponto
    varsVivas[i] = varsVivas[i + 1];

    // Remove a variável de destino (já foi definida neste ponto)
    varsVivas[i].erase(dependencias[i].first);

    // Adiciona a variável fonte (já está sendo usada neste ponto)
    varsVivas[i].insert(dependencias[i].second);
  }

  // Constrói o grafo de interferência
  for (int i = 0; i < dependencias.size(); i++) {
    string destino = dependencias[i].first;

    // Todas as variáveis vivas aqui interferem com o alvo
    for (const string &varViva : varsVivas[i]) {
      if (indiceVar.find(varViva) != indiceVar.end()) {
        int u = indiceVar[destino];
        int v = indiceVar[varViva];

        // Adiciona aresta de interferência (não direcionada)
        grafoInterferencia[u].push_back(v);
        grafoInterferencia[v].push_back(u);
      }
    }
  }

  // Verifica se o grafo pode ser colorido com 2 cores
  cout << (podeColorir(grafoInterferencia, contadorVar) ? "OK" : "Compilation Error") << endl;

  return 0;
}