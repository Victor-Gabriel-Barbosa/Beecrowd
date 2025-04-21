#include <bits/stdc++.h>
using namespace std;

typedef struct Caminho {
  int inters;
  double chance;

  Caminho(int inter, double chance) : inters(inter), chance(chance) {}

  bool operator<(const Caminho& outro) const {
    return chance < outro.chance;
  }
} Caminho;

typedef struct Rua {
  int fim;        
  double chance;

  Rua(int dest, double chance) : fim(dest), chance(chance) {}
} Rua;

// Calcula a chance do caminho mais seguro entre dois pontos
double caminhoSeguroChicago(vector<vector<Rua>>& Chicago, int ini, int fim) {
  int qtInt = Chicago.size();
  vector<double> maxChance(qtInt, 0.0);
  priority_queue<Caminho> filaPrior;

  // Começa na rua inicial com chance máxima
  maxChance[ini] = 1.0;
  filaPrior.push(Caminho(ini, 1.0));

  while (!filaPrior.empty()) {
    Caminho atual = filaPrior.top();
    filaPrior.pop();
    int tempU = atual.inters;
    double chanceAtual = atual.chance;

    // Ignora se a chance atual é menor
    if (chanceAtual < maxChance[tempU]) continue;

    // Explora todas as ruas conectadas
    for (auto& rua : Chicago[tempU]) {
      int tempV = rua.fim;
      double novaChance = chanceAtual * (rua.chance / 100.0);

      if (novaChance > maxChance[tempV]) {
        maxChance[tempV] = novaChance;
        filaPrior.push(Caminho(tempV, novaChance));
      }
    }
  }

  // Retorna a chance em porcentagem
  return maxChance[fim] * 100.0;
}

int main() {
  int qtInt, qtRua;

  while ((cin >> qtInt >> qtRua) && qtInt) {
    vector<vector<Rua>> Chicago(1 + qtInt);

    while (qtRua--) {
      int ptF1, ptF2, chance;
      cin >> ptF1 >> ptF2 >> chance;

      Chicago[ptF1].push_back(Rua(ptF2, chance));
      Chicago[ptF2].push_back(Rua(ptF1, chance));
    }

    cout << fixed << setprecision(6) << caminhoSeguroChicago(Chicago, 1, qtInt) << " percent" << endl;
  }

  return 0;
}