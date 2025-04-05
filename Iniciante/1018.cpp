#include <iostream>
using namespace std;

int main() {
  int c, n100, n50, n20, n10, n5, n2, n1;

  cin >> c;
  cout << c << endl;
  
  n100 = c / 100;
  c = c % 100;
  n50 = c / 50;
  c = c % 50;
  n20 = c / 20;
  c = c % 20;
  n10 = c / 10;
  c = c % 10;
  n5 = c / 5;
  c = c % 5;
  n2 = c / 2;
  c = c % 2;
  n1 = c / 1;
  c = c % 1;

  cout << n100 << " nota(s) de R$ 100,00" << endl;
  cout << n50 << " nota(s) de R$ 50,00" << endl;
  cout << n20 << " nota(s) de R$ 20,00" << endl;
  cout << n10 << " nota(s) de R$ 10,00" << endl;
  cout << n5 << " nota(s) de R$ 5,00" << endl;
  cout << n2 << " nota(s) de R$ 2,00" << endl;
  cout << n1 << " nota(s) de R$ 1,00" << endl;
  
  return 0;
}