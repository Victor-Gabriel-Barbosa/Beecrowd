#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int hi, mi, hf, mf, duracao;

  cin >> hi >> mi >> hf >> mf;
  duracao = (hf * 60 + mf) - (hi * 60 + mi);
  if (duracao <= 0) duracao += 24 * 60;
  cout << "O JOGO DUROU " << duracao / 60 << " HORA(S) E " << duracao % 60 << " MINUTO(S)" << endl;

  return 0;
}