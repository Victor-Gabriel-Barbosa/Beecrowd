#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  string s1, s2;
  bool cabe;

  cin >> N;
  while (N--) {
    cin >> s1 >> s2;
    cabe = s1.size() >= s2.size() && s1.substr(s1.size() - s2.size()) == s2;
    cout << (cabe ? "encaixa" : "nao encaixa") << endl;
  }

  return 0;
}