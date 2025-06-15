#include <bits/stdc++.h>
using namespace std;

int tempo;
vector<vector<int>> grafo;
vector<int> tempoDescoberta, menorTempo;
set<int> pontosArticulacao;

void dfs(int vertice, int pai = -1) {
  tempoDescoberta[vertice] = menorTempo[vertice] = tempo++;
  int filhos = 0;
  for (int vizinho : grafo[vertice]) {
    if (vizinho == pai) continue;
    if (tempoDescoberta[vizinho] != -1) menorTempo[vertice] = min(menorTempo[vertice], tempoDescoberta[vizinho]);
    else {
      dfs(vizinho, vertice);
      menorTempo[vertice] = min(menorTempo[vertice], menorTempo[vizinho]);
      if (menorTempo[vizinho] >= tempoDescoberta[vertice] && pai != -1) pontosArticulacao.insert(vertice);
      filhos++;
    }
  }
  if (pai == -1 && filhos > 1) pontosArticulacao.insert(vertice);
}

int main() {
  int locais, rotas, numeroMapa = 1;
  while (cin >> locais && locais != 0) {
    map<string, int> nomeParaIndice;
    vector<string> indiceParaNome(locais);

    for (int i = 0; i < locais; i++) {
      cin >> indiceParaNome[i];
      nomeParaIndice[indiceParaNome[i]] = i;
    }

    grafo.assign(locais, vector<int>());
    cin >> rotas;

    for (int i = 0; i < rotas; i++) {
      string origem, destino;
      cin >> origem >> destino;
      int u = nomeParaIndice[origem];
      int v = nomeParaIndice[destino];
      grafo[u].push_back(v);
      grafo[v].push_back(u);
    }

    tempoDescoberta.assign(locais, -1);
    menorTempo.assign(locais, -1);
    pontosArticulacao.clear();
    tempo = 0;

    for (int i = 0; i < locais; i++) if (tempoDescoberta[i] == -1) dfs(i);

    vector<string> locaisComCamera;
    for (int ponto : pontosArticulacao) locaisComCamera.push_back(indiceParaNome[ponto]);

    sort(locaisComCamera.begin(), locaisComCamera.end());

    cout << "City map #" << numeroMapa++ << ": " << locaisComCamera.size() << " camera(s) found\n";
    for (string &local : locaisComCamera) cout << local << "\n";
    cout << "\n";
  }
  return 0;
}
