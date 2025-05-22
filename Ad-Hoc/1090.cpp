#include <bits/stdc++.h>
using namespace std;

struct Carta {
  int numero;
  int tipo;
};

// Verifica se três cartas formam um set válido
bool forma_set(const Carta &c1, const Carta &c2, const Carta &c3) {
  // Verifica o número de figuras
  bool num_iguais = (c1.numero == c2.numero && c2.numero == c3.numero);
  bool num_diferentes = (c1.numero != c2.numero && c1.numero != c3.numero && c2.numero != c3.numero);

  // Verifica o tipo de figura
  bool tipo_iguais = (c1.tipo == c2.tipo && c2.tipo == c3.tipo);
  bool tipo_diferentes = (c1.tipo != c2.tipo && c1.tipo != c3.tipo && c2.tipo != c3.tipo);

  return (num_iguais || num_diferentes) && (tipo_iguais || tipo_diferentes);
}

int main() {
  int N;
  while (cin >> N && N != 0) {
    vector<Carta> cartas(N);

    for (int i = 0; i < N; i++) {
      string numero, tipo;
      cin >> numero >> tipo;

      // Converte texto para valores numéricos
      if (numero == "um") cartas[i].numero = 1;
      else if (numero == "dois") cartas[i].numero = 2;
      else cartas[i].numero = 3;

      if (tipo.find("circulo") != string::npos) cartas[i].tipo = 1;
      else if (tipo.find("quadrado") != string::npos) cartas[i].tipo = 2;
      else cartas[i].tipo = 3;
    }

    // Encontra todos os sets possíveis
    vector<vector<int>> sets;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        for (int k = j + 1; k < N; k++) {
          if (forma_set(cartas[i], cartas[j], cartas[k])) sets.push_back({i, j, k});
        }
      }
    }

    // Algoritmo guloso para escolher o máximo de sets não sobrepostos
    vector<bool> usado(N, false);
    int max_sets = 0;

    while (true) {
      bool encontrou = false;
      for (const auto &set : sets) {
        bool pode_usar = true;
        for (int carta : set) {
          if (usado[carta]) {
            pode_usar = false;
            break;
          }
        }

        if (pode_usar) {
          encontrou = true;
          max_sets++;
          for (int carta : set) usado[carta] = true;
          break;
        }
      }

      if (!encontrou) break;
    }

    cout << max_sets << endl;
  }

  return 0;
}