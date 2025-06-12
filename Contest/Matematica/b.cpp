#include <bits/stdc++.h>
using namespace std;

bool ehPalindromo(const string& s) {
  int n = s.size();
  for (int i = 0; i < n / 2; i++) if (s[i] != s[n - i - 1]) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  while (N--) {
    long int num, cont = 0;
    cin >> num;
    
    string temp = to_string(num);
    
    while (!ehPalindromo(temp)) {
      string inv = temp;
      reverse(inv.begin(), inv.end());
      num += stoi(inv);
      cont++;
      temp = to_string(num);
    }

    cout << cont << " " << num << endl;
  }

  return 0;
}