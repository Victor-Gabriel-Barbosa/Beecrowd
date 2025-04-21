using namespace std;
#include <bits/stdc++.h>

int main() {
  string palavra;
  cin >> palavra;

  cout << (palavra.size() < 10 ? "palavrinha" : "palavrao") << endl;

  return 0;
}