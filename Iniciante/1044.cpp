#include <iostream>
using namespace std;

int main() {
  int a, b;
  
  cin >> a >> b;
  cout <<  ((!(a % b) || !(b % a)) ? "Sao Multiplos" : "Nao sao Multiplos") << endl;

  return 0;
}