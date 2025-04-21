using namespace std;
#include <bits/stdc++.h>

int main() {
  int N, X;
  string titans;
  cin >> N >> X;
  cin >> titans;
  int P, M, G;
  cin >> P >> M >> G;

  multiset<int> muralhas;
  muralhas.insert(X); 
  
  for (char titan : titans) {
    int tamTitan = (titan == 'P') ? P : (titan == 'M') ? M : G;
    
    auto it = muralhas.lower_bound(tamTitan);
    
    if (it != muralhas.end()) {
      int alturaRestante = *it - tamTitan;
      muralhas.erase(it);
      if (alturaRestante > 0) muralhas.insert(alturaRestante);
    } else { 
      muralhas.insert(X);
      it = muralhas.find(X);
      int alturaRestante = X - tamTitan;
      muralhas.erase(it);
      if (alturaRestante > 0) muralhas.insert(alturaRestante);
    }
  }

  cout << muralhas.size() << endl;
  
  return 0;
}