#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore();
  
  while (N--) {
    string linha, temp, res;
    getline(cin, linha);
    int tam = linha.length();
    
    temp = linha.substr(0, tam / 2);
    reverse(temp.begin(), temp.end());
    res = temp;
    temp = linha.substr(tam / 2, tam);
    reverse(temp.begin(), temp.end());
    res += temp;

    cout << res << endl;
  }
  
  return 0;
}