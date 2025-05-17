#include <bits/stdc++.h>
using namespace std;

int main() {
  string linha;
  while (getline(cin, linha)) {
    int T = 0;
    stringstream ss(linha);
    string atual, anterior, cache = " ";

    ss >> anterior;
    while (ss >> atual) {
      if (tolower(atual[0]) == tolower(anterior[0]) && tolower(cache[0]) != tolower(atual[0])) T++;
      cache = anterior;
      anterior = atual;
    }

    cout << T << endl;
  }
}