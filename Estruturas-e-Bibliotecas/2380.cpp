#include <iostream>
#include <vector>
using namespace std;



int main() {
  int N, b;
  vector<pair<int, int>> banco;

  cin >> N >> b;
  while (b--) {
    char Op;
    int C1, C2;
    cin >> Op >> C1 >> C2;

    if (Op == 'F') banco.push_back(make_pair(C1, C2));
    else if (Op == 'C') {
      bool achou = false;
      for (size_t i = 0; i < banco.size(); i++) {
        if (banco[i] == make_pair(C1, C2)) achou = true;
      }
      cout << (achou ? 'S' : 'N') << endl;
    }
  }

  return 0;
}