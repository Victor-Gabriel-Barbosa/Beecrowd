#include <bits/stdc++.h>
using namespace std;

int main() {
  string frase;

  while (getline(cin, frase)) {
    vector<string> palavras;
    string palavra;
    istringstream stream(frase);
    while (stream >> palavra) palavras.push_back(palavra);

    for (size_t i = 0; i < palavras.size(); i++) {
      reverse(palavras[i].begin(), palavras[i].end());
      cout << palavras[i];
      if (i < palavras.size() - 1) cout << " ";
    }
    cout << endl;
  }

  return 0;
}