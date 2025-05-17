#include <bits/stdc++.h>
using namespace std;

int main() {
  string tagOriginal, texto;
  int valorNumerico;

  // Leitura da entrada: tag original, valor numérico e texto
  while (getline(cin, tagOriginal) && (cin >> valorNumerico) && cin.ignore() &&
         getline(cin, texto)) {
    string tagSubstituta = to_string(valorNumerico);
    string resultado = "";

    size_t i = 0;
    while (i < texto.size()) {
      // Se encontrou o início de uma possível tag
      if (texto[i] == '<') {
        resultado += '<';
        i++;

        // Está dentro de uma tag
        string conteudoTag = "";
        while (i < texto.size() && texto[i] != '>') {
          conteudoTag += texto[i];
          i++;
        }

        // Processa o conteúdo da tag
        string conteudoProcessado = "";
        size_t j = 0;
        while (j < conteudoTag.size()) {
          // Verifica se encontrou a tagOriginal (ignorando case)
          bool encontrou = true;
          if (j + tagOriginal.size() <= conteudoTag.size()) {
            for (size_t k = 0; k < tagOriginal.size(); k++) {
              if (tolower(conteudoTag[j + k]) != tolower(tagOriginal[k])) {
                encontrou = false;
                break;
              }
            }

            if (encontrou) {
              conteudoProcessado += tagSubstituta;
              j += tagOriginal.size();
            } else {
              conteudoProcessado += conteudoTag[j];
              j++;
            }
          } else {
            conteudoProcessado += conteudoTag[j];
            j++;
          }
        }

        resultado += conteudoProcessado;

        // Adiciona o fechamento da tag, se existir
        if (i < texto.size()) {
          resultado += texto[i]; // Adiciona o '>'
          i++;
        }
      } else {
        // Caractere normal, fora de tag
        resultado += texto[i];
        i++;
      }
    }

    cout << resultado << endl;
  }

  return 0;
}