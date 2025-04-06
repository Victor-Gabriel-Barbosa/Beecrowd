#include <iostream>
using namespace std;

int main() {
  int N, t1, t2;
  string s1, s2;

  cin >> N;
  while (N--) {
    cin >> s1 >> s2;

    t1 = s1.length();
    t2 = s2.length();
    
    for (int i = 0, j = 0; i < t1 || j < t2; i++, j++) {
      if (i < t1) cout << s1[i];
      if (j < t2) cout << s2[j];
    }
    cout << endl;
  }

  
  return 0;
}