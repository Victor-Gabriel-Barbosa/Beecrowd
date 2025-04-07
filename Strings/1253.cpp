#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  while (N--) {
    string cifra;
    int deslocado;
    cin >> cifra >> deslocado;

    string decifra = cifra;
    for (size_t i = 0; i < cifra.size(); ++i) {
      char letra = cifra[i];
      decifra[i] = letra - deslocado;
      if (decifra[i] < 'A') decifra[i] += 26;
      if (decifra[i] > 'Z') decifra[i] -= 26;
    }
    
    cout << decifra << endl;
  }
}