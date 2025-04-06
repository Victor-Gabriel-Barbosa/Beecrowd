#include <iostream>
using namespace std;

int main() {
  int inter = 0, gremio = 0, contGren = 0, loop = 1;

  while (loop == 1) {
    int g, i;
    cin >> i >> g;
    cin.ignore();

    if (g > i) gremio++;
    else if (i > g) inter++;

    cout << "Novo grenal (1-sim 2-nao)" << endl;
    do {
      cin >> loop;
      cin.ignore();
    } while (loop != 1 && loop != 2);
    contGren++;
  }

  cout << contGren << " grenais" << endl;
  cout << "Inter:" << inter << endl;
  cout << "Gremio:" << gremio << endl;
  cout << "Empates:" << contGren - inter - gremio << endl;
  if (inter > gremio) cout << "Inter venceu mais" << endl;
  else if (gremio > inter) cout << "Gremio venceu mais" << endl;
  else cout << "Nao houve vencedor" << endl;

  return 0;
}