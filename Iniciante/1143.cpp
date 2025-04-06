#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore();
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) cout << pow(i + 1, j + 1) << ((j != 2) ? " " : "");
    cout << endl;
  }

  return 0;
}