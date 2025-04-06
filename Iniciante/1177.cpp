#include <iostream>
using namespace std;

int main() {
  int tam = 1000, T, N[tam];
  cin >> T;
  cin.ignore();

  for (int i = 0; i < tam; i++) N[i] = i % T;
  for (int i = 0; i < tam; i++) cout << "N[" << i << "] = " << N[i] << endl;
  
  return 0;
}