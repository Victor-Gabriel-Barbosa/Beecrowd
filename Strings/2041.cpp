#include <bits/stdc++.h>
using namespace std; 

string proximo(string sequencia) {
  string res = "";
  char temp = sequencia[0];
  int ct = 1;
  for (size_t i = 1; i < sequencia.size(); i++) {
    if (sequencia[i] == temp) ct++;
    else {
      res += to_string(ct) + temp;
      ct = 1;
      temp = sequencia[i];
    }
  }
  return res + to_string(ct) + temp;;
}

string Godelito(string sequencia, int n) {
  for (int i = 1; i < n; i++) sequencia = proximo(sequencia);
  return sequencia;
}

int main() {
  int n;
  while (cin >> n) cout << Godelito("3", n) << endl;
  return 0;
}