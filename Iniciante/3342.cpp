using namespace std;
#include <bits/stdc++.h>

int main() {
  int N;
  cin >> N;
  
  cout << ceil(pow(N, 2) / 2) << " casas brancas e " << (int)pow(N, 2) / 2 << " casas pretas" << endl;

  return 0;
}