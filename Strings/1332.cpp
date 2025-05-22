#include <bits/stdc++.h>
using namespace std;

int distancia(const string& str1, const string& str2) {
  int m = str1.length();
  int n = str2.length();

  if (m == 0)
    return n;
  if (n == 0)
    return m;

  int i = 0;
  while (i < m && i < n && str1[i] == str2[i])
    i++;

  if (i > 0)
    return distancia(str1.substr(i), str2.substr(i));

  int j = 0;
  while (j < m && j < n && str1[m - j - 1] == str2[n - j - 1])
    j++;

  if (j > 0)
    return distancia(str1.substr(0, m - j), str2.substr(0, n - j));

  vector<int> anterior(n + 1);
  vector<int> atual(n + 1);

  for (int j = 0; j <= n; j++)
    anterior[j] = j;

  for (int i = 1; i <= m; i++) {
    atual[0] = i;

    for (int j = 1; j <= n; j++) {
      if (str1[i - 1] == str2[j - 1])
        atual[j] = anterior[j - 1];
      else
        atual[j] = 1 + min({atual[j - 1], anterior[j], anterior[j - 1]});
    }

    anterior = atual;
  }

  return anterior[n];
}

string similar(const map<string, string>& dicionario, const string& palavra) {
  int menor = INT_MAX;
  string resposta;

  for (const auto &[chave, valor] : dicionario) {
    int dist = distancia(palavra, chave);
    if (dist < menor) {
      menor = dist;
      resposta = valor;
    }
  }

  return resposta;
}

int main() {
  int N;
  cin >> N;
  cin.ignore();

  const map<string, string> numeros = {
      {"one", "1"},       {"two", "2"},        {"three", "3"},
      {"four", "4"},      {"five", "5"},       {"six", "6"},
      {"seven", "7"},     {"eight", "8"},      {"nine", "9"},
      {"ten", "10"},      {"eleven", "11"},    {"twelve", "12"},
      {"thirteen", "13"}, {"fourteen", "14"},  {"fifteen", "15"},
      {"sixteen", "16"},  {"seventeen", "17"}, {"eighteen", "18"},
      {"nineteen", "19"}, {"twenty", "20"}};

  while (N--) {
    string palavra;
    getline(cin, palavra);
    cout << similar(numeros, palavra) << endl;
  }

  return 0;
}