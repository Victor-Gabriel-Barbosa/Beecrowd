#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  string faixa;

  while (getline(cin, faixa)) {
    sort(faixa.begin(), faixa.end());
    faixa.erase(unique(faixa.begin(), faixa.end()), faixa.end());
    faixa.erase(remove(faixa.begin(), faixa.end(), ' '), faixa.end());

    if (faixa.empty()) {
      cout << endl;
      continue;
    }

    vector<pair<char, char>> faixas;

    char inicio = faixa[0];
    char fim = faixa[0];

    for (size_t i = 1; i < faixa.size(); i++) {
      if (faixa[i] == fim + 1) fim = faixa[i];
      else {
        faixas.push_back(make_pair(inicio, fim));
        inicio = faixa[i];
        fim = faixa[i];
      }
    }
    
    faixas.push_back(make_pair(inicio, fim));

    for (size_t i = 0; i < faixas.size(); i++) {
      cout << faixas[i].first << ":" << faixas[i].second;
      if (i < faixas.size() - 1) cout << ", ";
    }
    cout << endl;
  }

  return 0;
}