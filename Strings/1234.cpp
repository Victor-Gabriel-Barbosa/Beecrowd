#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string rebolaLetrinha(string frase) { // :)
  bool auxMaiuscula = true;
  string resultado = frase;
  
  for (size_t i = 0; i < frase.length(); i++) {
    if (isalpha(frase[i])) {
      resultado[i] = auxMaiuscula ? toupper(frase[i]) : tolower(frase[i]);
      auxMaiuscula = !auxMaiuscula;
    }
  }
  
  return resultado;
}

int main() {
  string linha;
  
  while (getline(cin, linha)) if (!linha.empty()) cout << rebolaLetrinha(linha) << endl;
  
  return 0;
}