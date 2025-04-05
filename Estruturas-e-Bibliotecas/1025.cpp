#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    int numCasos = 1;
    
    cin >> N >> Q;
    while (N != 0 || Q != 0) {
      vector<int> marmores(N);
      for (int i = 0; i < N; i++) cin >> marmores[i];
      
      sort(marmores.begin(), marmores.end());
      
      cout << "CASE# " << numCasos << ":" << endl;
      for (int i = 0; i < Q; i++) {
        int consultas;
        cin >> consultas;
        
        bool aux = false;
        for (int j = 0; j < N; j++) {
          if (marmores[j] == consultas) {
            cout << consultas << " found at " << (j + 1) << endl;
            aux = true;
            break;
          }
        }
        
        if (!aux) cout << consultas << " not found" << endl;
      }
      
      numCasos++;
      cin >> N >> Q; 
    }

    return 0;
}