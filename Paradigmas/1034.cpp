#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Calcula o número mínimo de blocos de gelo necessários
long minDeBlocos(vector<int>& blocosDeGelo, int tamComp) { 
  size_t qtdTip = blocosDeGelo.size() - 1;
  vector<int> mPD((tamComp + 1), (INT_MAX - 1));
  mPD[0] = 0;

  // Preenche o vetor mPD com o número mínimo de blocos de gelo
  for (auto i = 1; i <= tamComp; i++) {
    for (size_t j = 0; j <= qtdTip; j++) {
      auto bloco = blocosDeGelo[j];
      if ((i >= bloco) && (mPD[i - bloco] != (INT_MAX - 1))) mPD[i] = min((mPD[i - bloco] + 1), mPD[i]);
    }
  }

  // Retorna o número mínimo de blocos de gelo necessários ou -1 se não existir
  return ((mPD[tamComp] == (INT_MAX - 1)) ? -1 : mPD[tamComp]);
}

int main() {
  int numInst;
  cin >> numInst; 

  // Para cada instância lê a quantidade de tipos de blocos de gelo e o tamanho do compartimento
  while (numInst--) {
    int qtdTip, tamComp; 
    cin >> qtdTip >> tamComp;

    vector<int> blocosDeGelo(qtdTip);
    for (auto i = 0; i < qtdTip; i++) cin >> blocosDeGelo[i];

    cout << minDeBlocos(blocosDeGelo, tamComp) << endl;
  }

  return 0;
}