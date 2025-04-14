#include <bits/stdc++.h>
using namespace std;

bool palindromo(const string& palavra, size_t ini, size_t fim) {
  while (ini < fim) if (palavra[ini++] != palavra[fim--]) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N;
  string palavra;
  cin >> N >> palavra;

  int tam = palavra.size();
  int cont = 0;

  for (int i = 0; i <= tam - N; i++) if (palindromo(palavra, i, i + N - 1)) cont++;

  cout << cont << endl;

  return 0;
}