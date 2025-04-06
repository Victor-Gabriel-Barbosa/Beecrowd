#include <iostream>
using namespace std;

int main() {
  int alc = 0, gas = 0, die = 0; 

  int opcao = 0;

  while (opcao != 4) {
    cin >> opcao;
    cin.ignore();

    switch (opcao) {
      case 1: alc++; break;
      case 2: gas++; break;
      case 3: die++; break;
      default: break;
    }
  }

  cout << "MUITO OBRIGADO" << endl;
  cout << "Alcool: " << alc << endl;
  cout << "Gasolina: " << gas << endl;
  cout << "Diesel: " << die << endl;

  return 0;
}