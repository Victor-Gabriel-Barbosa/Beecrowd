#include <bits/stdc++.h>
using namespace std;

int main() {
  string entrada;
  int N;
  while (getline(cin, entrada) && (cin >> N)) {
    cin.ignore();
    
    int cont = 0;
    for (size_t i = 0; i < entrada.size(); i++) {
      if (entrada[i] == 'R') {
        int contR = 1; 
        for (size_t j = i + 1; j < entrada.size(); j++) { 
          if (entrada[j] == 'R') {
            contR++;
            i++;
          } else break;
        }
        cont += ceil((double) contR / N);
      } else if (entrada[i] == 'W') cont++;
    }

    cout << cont << endl;
  }
}