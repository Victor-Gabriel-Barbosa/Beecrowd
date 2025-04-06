#include <iostream>
using namespace std;

int main() {
  int N, maior = 0, posi = 0;

  for (int i = 1; i <= 100; i++) {
    cin >> N;
    if (N > maior) {
      maior = N;
      posi = i;
    }
  }
  cout << maior << endl << posi << endl;

  return 0;
}