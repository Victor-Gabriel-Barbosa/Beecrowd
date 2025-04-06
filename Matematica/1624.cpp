#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  
  do {
    cin >> N;
    if (N == 0) continue; 
    
    vector<int> precos(N);
    vector<int> pesos(N);
    
    for (int i = 0; i < N; i++) cin >> precos[i] >> pesos[i];
    
    cin >> M;
    
    vector<int> pd(M + 1, 0);
    
    for (int i = 0; i < N; i++) {
      for (int peso = M; peso >= pesos[i]; peso--) {
        pd[peso] = max(pd[peso], pd[peso - pesos[i]] + precos[i]);
      }
    }
    
    cout << pd[M] << endl;
  } while (N != 0);
  
  return 0;
}