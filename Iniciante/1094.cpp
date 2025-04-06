#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main() {
  int N, contR = 0, contS = 0, contC = 0;
  cin >> N;
  cin.ignore();

  while (N--) {
    int Q;
    char T;

    cin >> Q >> T;
    cin.ignore();

    if (T == 'R') contR += Q;
    else if (T == 'S') contS += Q;
    else if (T == 'C') contC += Q;
  }
    
  cout << "Total: " << contR + contS + contC << " cobaias" << endl;
  cout << "Total de coelhos: " << contC << endl;
  cout << "Total de ratos: " << contR << endl;
  cout << "Total de sapos: " << contS << endl;
  cout << fixed << setprecision(2) << "Percentual de coelhos: " << (contC * 100.0) / (contR + contS + contC) << " %" << endl;
  cout << fixed << setprecision(2) << "Percentual de ratos: " << (contR * 100.0) / (contR + contS + contC) << " %" << endl;
  cout << fixed << setprecision(2) << "Percentual de sapos: " << (contS * 100.0) / (contR + contS + contC) << " %" << endl;

  return 0;
}