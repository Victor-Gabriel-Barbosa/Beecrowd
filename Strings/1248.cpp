#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore();
  
  while (N--) {
    string dieta, cafe, almoco;
    getline(cin, dieta);
    getline(cin, cafe);
    getline(cin, almoco);
    
    string jantar = dieta;
    bool cheater = false;
    
    for (char c : cafe) {
      size_t pos = jantar.find(c);
      if (pos != string::npos) jantar.erase(pos, 1);
      else {
        cheater = true;
        break;
      }
    }
    
    if (!cheater) {
      for (char c : almoco) {
        size_t pos = jantar.find(c);
        if (pos != string::npos) jantar.erase(pos, 1);
        else {
          cheater = true;
          break;
        }
      }
    }
    
    if (cheater) cout << "CHEATER" << endl;
    else {
      sort(jantar.begin(), jantar.end());
      cout << jantar << endl;
    }
  }
  
  return 0;
}