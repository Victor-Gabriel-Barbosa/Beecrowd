#include <bits/stdc++.h>
using namespace std;

bool testarK(long long k, int n) {
  list<int> aranhas;
  for (int i = 1; i <= 2 * n; i++) aranhas.push_back(i);

  auto it = aranhas.begin();

  for (int mortos = 0; mortos < n; mortos++) {
    for (long long j = 1; j < k; j++) {
      it++;
      if (it == aranhas.end()) it = aranhas.begin();
    }

    int posicao = *it;
    auto temp = it;
    it++;
    if (it == aranhas.end()) it = aranhas.begin();
    aranhas.erase(temp);

    if (posicao <= n) return false; 
  }

  return true;
}

int main() {
  int N;
  cin >> N;

  if (N == 1) {
    cout << "2" << endl;
    return 0;
  } else if (N == 2) {
    cout << "7" << endl;
    return 0;
  } else if (N == 3) {
    cout << "5" << endl;
    return 0;
  }

  long long k = N + 1;
  while (!testarK(k, N)) k++;

  cout << k << endl;
  return 0;
}