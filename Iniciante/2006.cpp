#include <iostream>
using namespace std;

int main() {
  int T, A, B, C, D, E;
  cin >> T >> A >> B >> C >> D >> E;

  cout << (T == A ? 1 : 0) +
          (T == B ? 1 : 0) +
          (T == C ? 1 : 0) +
          (T == D ? 1 : 0) +
          (T == E ? 1 : 0) << endl;

  return 0;
}