#include <iostream>
using namespace std;

int main() {
  int T; 
  cin >> T;

  for (int t = 0; t < T; t++) {
    int PA, PB;    
    double G1, G2; 

    cin >> PA >> PB >> G1 >> G2;

    int anos = 0;
    while (PA <= PB) {
      PA += int(PA * G1 / 100);
      PB += int(PB * G2 / 100);
      anos++;

      if (anos > 100) break;
    }

    if (anos > 100) cout << "Mais de 1 seculo." << endl;
    else cout << anos << " anos." << endl;
  }

  return 0;
}