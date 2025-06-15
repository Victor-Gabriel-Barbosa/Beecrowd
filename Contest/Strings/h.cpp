#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b;

  while (getline(cin, a) && getline(cin, b)) {
    vector<int> fa(26, 0), fb(26, 0);

    for (char c : a) fa[c - 'a']++;
    for (char c : b) fb[c - 'a']++;

    string seq = "";
    for (int i = 0; i < 26; i++) {
      int fm = min(fa[i], fb[i]);
      while (fm--) seq += (char)('a' + i);
    }

    cout << seq << endl;
  }

  return 0;
}