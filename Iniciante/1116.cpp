#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore();

  while (N--) {
    int n1, n2;
    cin >> n1 >> n2;
    cin.ignore();

    if (n2 == 0) {
      cout << "divisao impossivel" << endl;
      continue;
    }

    cout << fixed << setprecision(1);
    cout << (double) n1 / n2 << endl;
  }

  return 0;
}