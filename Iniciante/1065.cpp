#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int num, cont = 0;
  
  for (int i = 0; i < 5; i++) {
    cin >> num;
    if (!(num % 2)) cont++;
  }
  cout << cont << " valores pares" << endl;
  
  return 0;
}