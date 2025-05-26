#include <bits/stdc++.h>
using namespace std;

string Bazinga(string jogador1, string jogador2) {
  // Estrutura onde a chave vence todos os valores no vetor
  map<string, vector<string>> regras = {
    {"tesoura", {"papel", "lagarto"}},
    {"papel", {"pedra", "Spock"}},
    {"pedra", {"lagarto", "tesoura"}},
    {"lagarto", {"Spock", "papel"}},
    {"Spock", {"tesoura", "pedra"}}
  };
  
  // Sheldon vence
  auto it = regras.find(jogador1);
  if (it != regras.end()) {
    for (const string& derrota : it->second) {
      if (derrota == jogador2) {
        return "Bazinga!";
      }
    }
  }
  
  // Raj vence
  it = regras.find(jogador2);
  if (it != regras.end()) {
    for (const string& derrota : it->second) {
      if (derrota == jogador1) {
        return "Raj trapaceou!";
      }
    }
  }
  
  // Empate
  return "De novo!";
}

int main() {
  int T;

  cin >> T;
  cin.ignore();

  int caso = 1;
  while (T--) {
    string entrada;
    getline(cin, entrada);
    stringstream ss(entrada);
    string jogador1, jogador2;
    ss >> jogador1 >> jogador2;

    cout << "Caso #" << caso++ << ": " << Bazinga(jogador1, jogador2) << endl;
  }

  return 0;
}