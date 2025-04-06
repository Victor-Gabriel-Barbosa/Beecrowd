#include <iostream>
using namespace std;

int main() {
  int V[10];

  for (int i = 0; i < 10; i++) cin >> V[i];
  for (int i = 0; i < 10; i++) cout << "X[" << i << "] = " << (V[i] > 0 ? V[i] : 1) << endl;

  return 0;
}