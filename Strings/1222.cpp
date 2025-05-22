#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, L, C;

  while (cin >> N >> L >> C) {
    vector<string> palavras(N);
    for (int i = 0; i < N; i++) cin >> palavras[i];

    int numLinhas = 1;
    int numPaginas = 1;  
    int caracteresPorLinha = palavras[0].size();

    for (int i = 1; i < N; i++) {
      if (caracteresPorLinha + 1 + (int)palavras[i].size() <= C) caracteresPorLinha += 1 + (int)palavras[i].size(); 
      else {
        numLinhas++;
        caracteresPorLinha = palavras[i].size();
        
        if (numLinhas > L) {
          numPaginas++;
          numLinhas = 1;
        }
      }
    }

    cout << numPaginas << endl;
  }
  
  return 0;
}