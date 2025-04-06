#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int N;
  string jazida;

  cin >> N;
  cin.ignore(); 

  while (N--) {
    int contDimas = 0;
    getline(cin, jazida);

    jazida.erase(remove(jazida.begin(), jazida.end(), '.'), jazida.end());

    size_t posi = jazida.find("<>");
    while (posi != string::npos) {
      contDimas++;
      jazida.erase(posi, 2);
      posi = jazida.find("<>");
    }

    cout << contDimas << endl;
  }
}