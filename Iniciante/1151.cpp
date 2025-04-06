#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore();

  int a = 0, b = 1;
  cout << a << " " << b << " ";
  for (int i = 2; i < N; ++i) {
    int c = a + b;
    cout << c << (i != N - 1 ? " " : "");
    a = b;
    b = c;
  }
  cout << endl;

  return 0;
}