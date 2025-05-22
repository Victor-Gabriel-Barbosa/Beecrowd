#include <bits/stdc++.h>
using namespace std;

bool isPalavraValida(const string& str) {
  if (str.empty()) return false;
  
  // Verifica se a palavra termina com ponto
  bool terminaComPonto = (str.back() == '.');
  
  // Tamanho efetivo da palavra (sem o ponto final, se houver)
  int tamanhoEfetivo = terminaComPonto ? str.size() - 1 : str.size();
  
  if (tamanhoEfetivo == 0) return false; // Se for só um ponto, não é palavra válida
  
  // Verifica se todos os caracteres (exceto o possível ponto final) são letras
  for (int i = 0; i < tamanhoEfetivo; i++) if (!isalpha(str[i])) return false;
  
  return true;
}

int main() {
  string problema;
  
  while (getline(cin, problema)) {
    istringstream ss(problema);
    string palavra;
    int comprimento = 0, qtd = 0;

    while (ss >> palavra) {
      if (isPalavraValida(palavra)) {
        // Se termina com ponto, não conta o ponto no comprimento
        if (palavra.back() == '.') comprimento += palavra.size() - 1;
        else comprimento += palavra.size();
        qtd++;
      }
    }

    if (qtd == 0) {
      cout << "250" << endl;
      continue;
    }

    int media = comprimento / qtd;
    if (media <= 3) cout << "250" << endl;
    else if (media == 4 || media == 5) cout << "500" << endl;
    else cout << "1000" << endl;
  }

  return 0;
}