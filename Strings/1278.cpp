#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string trim(const string &frase) {
  istringstream iss(frase);
  ostringstream oss;
  string palavra;
  bool primeiro = true;

  while (iss >> palavra) {
    if (!primeiro) oss << ' ';
    oss << palavra;
    primeiro = false;
  }

  return oss.str();
}

int main() {
  int N;
  bool t1 = true;

  do {
    cin >> N;
    if (N == 0) continue;
    
    cin.ignore();
    
    if (!t1) cout << endl;
    else t1 = false;
    
    vector<string> texto;
    while (N--) {
      string temp;
      getline(cin, temp);
      texto.push_back(trim(temp));
    }

    size_t maxT = 0;
    for (const string& linha : texto) maxT = max(maxT, linha.size());

    for (const string& linha : texto) {
      size_t espacos = maxT - linha.size();
      string espacosEsquerda(espacos, ' ');
      cout << espacosEsquerda << linha << endl;
    }
  } while (N != 0);

  return 0;
}