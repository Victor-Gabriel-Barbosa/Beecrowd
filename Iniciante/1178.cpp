#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int tam = 100; 
  double X, N[tam];
  cin >> X;
  cin.ignore();

  N[0] = X;
  for (int i = 1; i < tam; i++) N[i] = N[i - 1] / (double) 2;

  cout << fixed << setprecision(4);
  for (int i = 0; i < tam; i++) cout << "N[" << i << "] = " << N[i] << endl;
  
  return 0;
}