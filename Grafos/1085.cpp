#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int m;
  while (cin >> m && m != 0) {
    string origem, destino;
    cin >> origem >> destino;

    // Mapeia idiomas para suas palavras (otimização)
    unordered_map<string, vector<string>> idiomaPalavras;
    // Mapeia palavras para seus idiomas
    unordered_map<string, vector<string>> palavraIdiomas;
    set<string> todasPalavras;

    for (int i = 0; i < m; i++) {
      string idioma1, idioma2, palavra;
      cin >> idioma1 >> idioma2 >> palavra;

      palavraIdiomas[palavra].push_back(idioma1);
      palavraIdiomas[palavra].push_back(idioma2);
      idiomaPalavras[idioma1].push_back(palavra);
      idiomaPalavras[idioma2].push_back(palavra);
      todasPalavras.insert(palavra);
    }

    // Algoritmo de Dijkstra - otimizado
    unordered_map<string, int> distancia;
    for (const auto &palavra : todasPalavras) {
      distancia[palavra] = INT_MAX;
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> filaPrioridade;

    // Começa a partir das palavras no idioma de origem
    for (const auto &palavra : idiomaPalavras[origem]) {
      distancia[palavra] = palavra.length();
      filaPrioridade.push({distancia[palavra], palavra});
    }

    while (!filaPrioridade.empty()) {
      auto [dist, palavra] = filaPrioridade.top();
      filaPrioridade.pop();

      if (dist > distancia[palavra]) continue;

      // Para cada idioma da palavra atual
      for (const auto &idioma : palavraIdiomas[palavra]) {
        // Para cada palavra do mesmo idioma
        for (const auto &proxPalavra : idiomaPalavras[idioma]) {
          // Verifica se as palavras são diferentes e não começam com a mesma letra
          if (palavra != proxPalavra && palavra[0] != proxPalavra[0]) {
            int novaDist = distancia[palavra] + proxPalavra.length();
            if (novaDist < distancia[proxPalavra]) {
              distancia[proxPalavra] = novaDist;
              filaPrioridade.push({novaDist, proxPalavra});
            }
          }
        }
      }
    }

    // Encontra a distância mínima para uma palavra no idioma de destino
    int distMin = INT_MAX;
    for (const auto &palavra : idiomaPalavras[destino]) {
      distMin = min(distMin, distancia[palavra]);
    }

    if (distMin == INT_MAX) cout << "impossivel" << endl;
    else cout << distMin << endl;
  }

  return 0;
}
