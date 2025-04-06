#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double M[12][12], num, soma = 0.0;
  int L; 
  char T;

  cin >> L >> T;

  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      cin >> num;
      M[i][j] = num;
    }
  }

  for (int i = 0; i < 12; i++) soma += M[L][i];

  cout << fixed << setprecision(1) << (T == 'S' ? soma : (soma / 12.0)) << endl;

  return 0;
}