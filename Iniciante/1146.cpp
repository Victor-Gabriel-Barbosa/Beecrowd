#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore();

  int fat = 1;
  for (int i = 1; i <= N; ++i) fat *= i;
  cout << fat << endl;

  return 0;
}