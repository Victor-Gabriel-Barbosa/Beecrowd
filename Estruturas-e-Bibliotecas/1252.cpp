#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N, M, num;
  vector<int> vetor;

  do {
    cin >> N >> M;
    cout << N << " " << M << endl;
    
    if (N == 0 && M == 0) continue;
    
    vetor.clear();
    
    for (int i = 0; i < N; i++) {
      cin >> num;
      vetor.push_back(num);
    }

    sort(vetor.begin(), vetor.end(), [M](int a, int b) {
      int modA = a % M;
      int modB = b % M;
  
      if (modA == modB) {
        bool aEhImpar = a % 2 != 0;
        bool bEhImpar = b % 2 != 0;
        
        if (aEhImpar && bEhImpar) return a > b; // Entre ímpares, maior primeiro
        if (!aEhImpar && !bEhImpar) return a < b; // Entre pares, menor primeiro
        return aEhImpar; // Ímpares antes de pares
      }
      return modA < modB;
    });

    for (int i = 0; i < N; i++) cout << vetor[i] << endl;
  } while (N != 0 || M != 0);

  return 0;
}