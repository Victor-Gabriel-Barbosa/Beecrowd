#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore();
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) cout << j + i * 4 + 1 << " ";
    cout << "PUM" << endl;
  }
  return 0;
}