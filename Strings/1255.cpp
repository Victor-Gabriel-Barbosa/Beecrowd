#include <bits/stdc++.h>
using namespace std;

struct frequencia {
  int cont = 0;
  char letra;
};

int main() {
  int N;
  cin >> N;
  cin.ignore(); 

  while (N--) {
    string linha;
    getline(cin, linha);

    vector<frequencia> frq;
    for (auto c : linha) {
      if (isalpha(c)) {
        c = tolower(c);
        bool encontrou = false;
        for (auto& f : frq) {
          if (f.letra == c) {
            f.cont++;
            encontrou = true;
            break;
          }
        }
        if (!encontrou) frq.push_back({1, c});
      }
    }

    sort(frq.begin(), frq.end(), [](const frequencia& a, const frequencia& b) {
      if (a.cont == b.cont) return a.letra < b.letra;
      return a.cont > b.cont;
    });

    int maior = frq[0].cont;
    for (const auto& f : frq) {
      if (f.cont == maior) cout << f.letra;
      else break;
    }
    cout << endl;
  }
}