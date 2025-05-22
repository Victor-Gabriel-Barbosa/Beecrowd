#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore();

  while (N--) {
    string linha, temp, resposta = "";
    getline(cin, linha);

    istringstream ss(linha);
    while (ss >> temp) resposta += temp[0];
    cout << resposta << endl;
  }

  return 0;
}