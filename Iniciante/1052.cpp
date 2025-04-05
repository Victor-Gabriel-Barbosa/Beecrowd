#include <iostream>
using namespace std;

int main() {
  string m[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  int n;
  
  cin >> n;
  cout << m[n - 1] << endl;
  
  return 0;
}