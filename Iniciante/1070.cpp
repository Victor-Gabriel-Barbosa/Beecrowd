#include <iostream>
using namespace std;

int main() {
  int x;
  
  cin >> x;
  for (int i = 0; i < 6; i++) cout << ((i == 0 && x % 2) ? x : (x += (x % 2) ? 2 : 1)) << endl;
  
  return 0;
}