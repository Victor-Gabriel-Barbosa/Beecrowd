#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  bool primeiro = true;
  
  while (cin >> N && N) {
    if (!primeiro) cout << endl;
    else primeiro = false;
    
    cin.ignore();
    vector<string> palavras;

    for (int i = 0; i < N; i++) {
      string palavra;
      cin >> palavra;
      palavras.push_back(palavra);
    }

    int maior = 0;
    for (auto palavra : palavras) maior = max(maior, (int)palavra.size());

    for (auto palavra : palavras) {
      int espacos = maior - palavra.size();
      while (espacos--) cout << " ";
      cout << palavra << endl;
    }
  }
  
  return 0;
}