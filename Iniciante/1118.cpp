#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double nt[2];
  int ntVal, opcao;
  
  do {
    ntVal = 0;
    while (ntVal < 2) {
      double temp;
      cin >> temp;
      
      if (temp < 0.0 || temp > 10.0) cout << "nota invalida" << endl;
      else {
        nt[ntVal] = temp;
        ntVal++;
      }
    }
    
    cout << fixed << setprecision(2);
    cout << "media = " << (nt[0] + nt[1]) / 2.0 << endl;
    
    opcao = 0;
    do {
      cout << "novo calculo (1-sim 2-nao)" << endl;
      cin >> opcao;
    } while (opcao != 1 && opcao != 2);
    
  } while (opcao == 1);
  
  return 0;
}