#include <bits/stdc++.h>
using namespace std; 

string Gago(string frase) {
  istringstream stream(frase);
  vector<string> palavras;
  string temp;
  while (stream >> temp) palavras.push_back(temp);

  string res = "";
  for (size_t i = 0; i < palavras.size(); i++) {
    if (palavras[i][0] == palavras[i][2] && palavras[i][1] == palavras[i][3]) {
      for (size_t j = 2; j < palavras[i].size(); j++) res += palavras[i][j];
    } else res += palavras[i];
    if (i < palavras.size() - 1) res += " ";
  }
  return res;
}


int main() {
  string entrada;
  getline(cin, entrada);
  cout << Gago(entrada) << endl;
  return 0;
}