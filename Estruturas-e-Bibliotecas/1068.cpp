#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string linha;

  while (getline(cin, linha)) {
    int contAberto = 0, contFechado = 0;
    bool erro = false;

    int tam = linha.length();
    for (int i = 0; i < tam; i++) {
      if (linha[i] == '(') {
        contAberto++;
        contFechado--;
      } else if (linha[i] == ')') {
        contFechado++;
        if (contAberto > 0) contAberto--;
        else {
          erro = true;
          break;
        }
      }
    }

    if (!erro && contAberto == 0 && contFechado == 0) cout << "correct" << endl;
    else cout << "incorrect" << endl;
  }
  
  return 0;
}