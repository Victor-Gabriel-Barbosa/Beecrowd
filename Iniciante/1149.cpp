#include <iostream>
using namespace std;

int main() {
  int A, N, soma = 0;

  cin >> A >> N;
  while (N <= 0) cin >> N;

  for (int i = 0; i < N; i++) soma += A + i;

  cout << soma << endl;
}