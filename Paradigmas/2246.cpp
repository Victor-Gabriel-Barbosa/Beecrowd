#include <bits/stdc++.h>
using namespace std;

// Verifica se é possível formar o valor exato com as moedas disponíveis
bool trocoEhPreciso(vector<long>& moedas, long valor) {
  vector<bool> mPD((valor + 1), false);
  mPD[0] = true;

  // Preenche o vetor mPD com as combinações possíveis de moedas
  for (auto moeda : moedas) for (auto i = valor; i >= moeda; i--) if (mPD[i - moeda]) mPD[i] = true;

  // Retorna se é possível formar o valor exato
  return mPD[valor];
}

int main() {
  long valCompra, qtdMoeda; 
  cin >> valCompra >> qtdMoeda;

  vector<long> moedas(qtdMoeda);
  while(qtdMoeda--) cin >> moedas[qtdMoeda];

  cout << (trocoEhPreciso(moedas, valCompra) ? 'S' : 'N') << endl;

  return 0;
}