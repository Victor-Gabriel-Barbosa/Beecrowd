#include <bits/stdc++.h>
using namespace std;

double tsp(const vector<vector<double>>& dist) {
  int N = dist.size();
  vector<vector<double>> dp(1 << N, vector<double>(N, 1e9)); // Usa 1e9 como "infinito"

  dp[1][0] = 0; // Começa da casa de João (ponto 0)

  for (int mask = 1; mask < (1 << N); ++mask) { // de 000..001 até 2^N - 1
    for (int i = 0; i < N; ++i) { // todos os pontos
      if (mask & (1 << i)) { // verifica se i faz parte do conjunto
        for (int j = 0; j < N; ++j) { // pega todos os j finais, para chegar em i
          if ((mask & (1 << j)) && i != j) { // verifica se j está no conjunto e != de i
            dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + dist[j][i]);
          }
        }
      }
    }
  }

  double min_cost = 1e9;
  for (int i = 0; i < N; ++i) {
    min_cost = min(min_cost, dp[(1 << N) - 1][i] + dist[i][0]); // Retorna à casa
  }

  return min_cost;
}

// Calcula a distância entre dois pontos
double calcDist(pair<int, int> X, pair<int, int> Y) {
  return sqrt(pow(X.first - Y.first, 2) + pow(X.second - Y.second, 2));
}

int main() {
  int N;
  while (cin >> N && N > 0) {
    int X, Y;
    cin >> X >> Y;

    vector<pair<int, int>> coords(N + 1); // +1 para incluir a casa
    coords[0] = {X, Y};

    // Lê as coordenadas dos focos de dengue
    for (int i = 1; i <= N; i++) cin >> coords[i].first >> coords[i].second;

    // Calcula as distâncias entre todos os pontos
    vector<vector<double>> dist(N + 1, vector<double>(N + 1));
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j <= N; j++) {
        dist[i][j] = calcDist(coords[i], coords[j]);
      }
    }

    cout << fixed << setprecision(2) << tsp(dist) << endl;
  }

  return 0;
}