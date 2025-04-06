#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long int T, N;
  vector<long long int> V = {0, 1}; 
  cin >> T;
  cin.ignore();

  while (T--) {
    cin >> N;
    cin.ignore();

    for (int i = V.size(); i <= N; i++) V.push_back(V[i - 1] + V[i - 2]);

    cout << "Fib(" << N << ") = " << V[N] << endl;
  }

  return 0;
}