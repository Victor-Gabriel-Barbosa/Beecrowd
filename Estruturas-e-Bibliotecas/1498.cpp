#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long llong;
typedef vector<llong> vetorLlong;
const int TAM_MAXIMO = 59;

class ProcessadorSolucao {
private:
  int numElementos;
  llong qtdValor[TAM_MAXIMO];
  vetorLlong valAcum[TAM_MAXIMO];
  llong valMax, valAnt;

  void lerEntrada() {
    for (int i = 0; i < TAM_MAXIMO; i++) valAcum[i].clear();

    memset(qtdValor, 0, sizeof(qtdValor));
    valMax = 0;

    llong valorLido;
    for (int i = 0; i < numElementos; i++) {
      cin >> valorLido;
      qtdValor[valorLido]++;
      valAcum[valorLido].push_back(1);
      valMax = max(valMax, valorLido);
    }
  }

  llong calcularResultado() {
    llong resultado = 0;
    valAnt = 1;

    for (llong atual = valMax; atual > 0; atual--) {
      resultado += qtdValor[atual] * valAnt;
      if (!valAcum[atual].empty()) valAnt = valAcum[atual].back();

      for (size_t i = 0; i < valAcum[atual - 1].size(); i++) valAcum[atual - 1][i] = valAnt;

      for (size_t i = 0; i + 1 < valAcum[atual].size(); i += 2) {
        llong combinado = valAcum[atual][i] + valAcum[atual][i + 1];
        valAcum[atual - 1].push_back(combinado);
      }
    }

    return resultado;
  }

public:
  void resolver() {
    while (cin >> numElementos) {
      lerEntrada();
      cout << calcularResultado() << endl;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ProcessadorSolucao processador;
  processador.resolver();

  return 0;
}