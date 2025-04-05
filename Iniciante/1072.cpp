#include <iostream>
using namespace std;

int main() {
  int x, temp, contIn = 0, contOut = 0;
  
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> temp;
    (temp >= 10 && temp <= 20) ? contIn++: contOut++;
  }
  cout << contIn << " in" << endl;
  cout << contOut << " out" << endl;
  
  return 0;
}