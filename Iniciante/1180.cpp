#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, temp;
  vector<int> v;  
  cin >> N;
  cin.ignore();

  for (int i = 0; i < N; ++i) {
    cin >> temp;
    cin.ignore();
    v.push_back(temp);
  }

  int minIndex = 0, minValue = v[0];
  for (int i = 1; i < N; ++i) {
    if (v[i] < minValue) {
      minValue = v[i];
      minIndex = i;
    }
  }
  cout << "Menor valor: " << minValue << endl;
  cout << "Posicao: " << minIndex << endl;


  return 0;
}