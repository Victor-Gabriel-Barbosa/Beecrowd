#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string entrada;
  
  while (getline(cin, entrada)) {
    entrada.erase(remove(entrada.begin(), entrada.end(), ' '), entrada.end());

    bool erro = false;

    string saida;
    for (size_t i = 0; i < entrada.size(); i++) {
      if (tolower(entrada[i]) == 'o') saida += '0';
      else if (entrada[i] == 'l') saida += '1';
      else if (isdigit(entrada[i]) || entrada[i] == '-') saida += entrada[i];
      else if (entrada[i] != ',') {
        erro = true;
        break;
      }
    }

    if (erro || saida.empty()) {
      cout << "error" << endl;
      continue;
    }

    try {
      long long numero = stoll(saida);
      if (numero > 2147483647 || numero < 0) cout << "error" << endl;
      else cout << numero << endl;
    } catch (const exception& e) {
      cout << "error" << endl;
    }
  }

  return 0;
}