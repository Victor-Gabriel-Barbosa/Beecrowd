#include <bits/stdc++.h>
using namespace std;

// Define os possíveis movimentos do cavalo
int hr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int vr[] = {-1, 1, -2, 2, -2, 2, -1, 1};

// Verifica se uma posição está dentro do tabuleiro
bool ehValido(int x, int y) { 
  return (x >= 0 && x < 8 && y >= 0 && y < 8); 
}

// Converte uma posição no formato do xadrez para coordenadas numéricas
pair<int, int> convertePosi(string pos) {
  return {pos[0] - 'a', pos[1] - '1'}; // 'a' -> 0, '1' -> 0
}

// BFS para encontrar o menor número de movimentos
int bfs(const string& inicio, const string& fim) {
  // Converte posições do formato do xadrez para coordenadas numéricas
  pair<int, int> posIni = convertePosi(inicio);
  pair<int, int> posFim = convertePosi(fim);

  // Se as posições inicial e final são iguais, retorna 0
  if (posIni.first == posFim.first && posIni.second == posFim.second) return 0;

  // Matriz para marcar posições visitadas
  vector<vector<bool>> visitado(8, vector<bool>(8, false));

  // Fila para BFS
  queue<pair<pair<int, int>, int>> fila; // ((lin, col), movimentos)

  // Marca a posição inicial como visitada
  visitado[posIni.first][posIni.second] = true;

  // Insere a posição inicial na fila com 0 movimentos
  fila.push({posIni, 0});

  while (!fila.empty()) {
    pair<int, int> atual = fila.front().first;
    int movi = fila.front().second;
    fila.pop();

    // Tenta todos os possíveis movimentos do cavalo
    for (int i = 0; i < 8; i++) {
      int auxLin = atual.first + hr[i];
      int auxCol = atual.second + vr[i];

      // Verifica se o novo movimento é válido
      if (ehValido(auxLin, auxCol)) {
        // Se chegou ao destino, retorna o número de movimentos + 1
        if (auxLin == posFim.first && auxCol == posFim.second) return movi + 1;

        // Se a posição não foi visitada, marca como visitada e adiciona à fila
        if (!visitado[auxLin][auxCol]) {
          visitado[auxLin][auxCol] = true;
          fila.push({{auxLin, auxCol}, movi + 1});
        }
      }
    }
  }

  return -1; // Caso não encontre um caminho, retorna -1 (não deve acontecer no xadrez)
}

int main() {
  string inicio, fim;

  while (cin >> inicio >> fim) {
    int movi = bfs(inicio, fim);
    cout << "To get from " << inicio << " to " << fim << " takes " << movi << " knight moves." << endl;
  }

  return 0;
}