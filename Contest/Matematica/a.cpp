#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;

  while (cin >> a >> b && (a || b)) {
    string sa = to_string(a);
    string sb = to_string(b);
    string res = to_string(a + b);

    int maxTam = max({sa.length(), sb.length(), res.length()});
    while ((int)sa.length() < maxTam) sa = '0' + sa;
    while ((int)sb.length() < maxTam) sb = '0' + sb;
    while ((int)res.length() < maxTam) res = '0' + res;

    int cont = 0;
    for (int i = maxTam - 1; i > 0; i--) { 
      if (res[i] - '0' < max(sa[i] - '0', sb[i] - '0')) {
        cont++;
        (sa[i - 1] - '0') > (sb[i - 1] - '0') ? sa[i - 1]++ : sb[i - 1]++;
      }
    }

    if (cont == 0) cout << "No carry operation." << endl;
    else if (cont == 1) cout << "1 carry operation." << endl;
    else cout << cont << " carry operations." << endl;
  }

  return 0;
}