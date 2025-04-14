#include <iostream>
#include <string>
using namespace std;

bool isVogal(char c) {
  string vogais = "aeiou";
  for (size_t i = 0; i < vogais.size(); i++) if (tolower(vogais[i]) == tolower(c)) return true;
  return false;
}

bool palindromo(string palavra) {
  for (size_t i = 0; i < palavra.size() / 2; i++) if (palavra[i] != palavra[palavra.size() - i - 1]) return false;
  return true;
}

string removeConsoante(string palavra) {
  string vogais;
  for (size_t i = 0; i < palavra.size(); i++) if (isVogal(palavra[i])) vogais += palavra[i];
  return vogais;
}

int main() {
  string risada;
  cin >> risada;

  cout << (palindromo(removeConsoante(risada)) ? "S" : "N") << endl;


  return 0;
}