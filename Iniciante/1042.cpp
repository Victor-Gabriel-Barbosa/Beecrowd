#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  vector<int> v(3);
  
  for (int i = 0; i < 3; i++) cin >> v[i];
  auto t = v;
  sort(v.begin(), v.end());
  for (int i = 0; i < 3; i++) cout << v[i] << endl;
  cout << endl;
  for (int i = 0; i < 3; i++) cout << t[i] << endl;
  
  return 0;
}