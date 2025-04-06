#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore();
  
  for (int i = 0; i < N * 2; i++) {
    if (i % 2 == 0) cout << (int) pow(i / 2 + 1, 1) << " " << (int) pow(i / 2 + 1, 2) << " " << (int) pow(i / 2 + 1, 3) << endl;
    else cout << (int) pow(i / 2 + 1, 1) << " " << (int) pow(i / 2 + 1, 2) + 1 << " " << (int) pow(i / 2 + 1, 3) + 1 << endl;
  }

  return 0;
}