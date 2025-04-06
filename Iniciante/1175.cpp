#include <iostream>
#include <iomanip>
using namespace std;


int main() {
  int T = 20, N[T];
  for (int i = 0; i < T; i++) cin >> N[i];

  for (int i = 0; i < T / 2; i++) {
    N[i] += N[T - i - 1];
    N[T - i - 1] = N[i] - N[T - i - 1];
    N[i] = N[i] - N[T - i - 1];
  }

  for (int i = 0; i < T; i++) cout << "N[" << i << "] = " << N[i] << endl;

  return 0;
}