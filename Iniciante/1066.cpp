#include <iostream>
using namespace std;

int main() {
  int num, contPar = 0, contImpar = 0, contPos = 0, contNeg = 0;
  
  for (int i = 0; i < 5; i++) {
    cin >> num;
    !(num % 2) ? contPar++ : contImpar++;
    (num > 0) ? contPos++ : num < 0 ? contNeg++ : 0;
  }

  cout << contPar << " valor(es) par(es)" << endl;
  cout << contImpar << " valor(es) impar(es)" << endl;
  cout << contPos << " valor(es) positivo(s)" << endl;
  cout << contNeg << " valor(es) negativo(s)" << endl;
  
  return 0;
}