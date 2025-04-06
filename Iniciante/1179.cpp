#include <iostream>
#include <iomanip>
using namespace std;

void imprime(int vet[], int cont) {
  for (int i = 0; i < cont; i++) {
    cout << (vet[i] % 2 ? "impar" : "par") << "[" << i << "] = " << vet[i] << endl;
  }
}

int main() {
  int impar[5], par[5], contI = 0, contP = 0, n;

  for (int i = 0; i < 15; i++) {
    cin >> n;
    cin.ignore();

    if (n % 2) {
      if (contI == 5) {
        imprime(impar, contI);
        contI = 0;
      }
      impar[contI++] = n;
    } else {
      if (contP == 5) {
        imprime(par, contP);
        contP = 0;
      }
      par[contP++] = n;
    }
  }

  imprime(impar, contI);
  imprime(par, contP);

  return 0;
}