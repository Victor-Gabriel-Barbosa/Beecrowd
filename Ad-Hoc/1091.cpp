#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;

  while (cin >> K && K) {
    cin.ignore();
    
    int N, M;
    cin >> N >> M;
    cin.ignore();

    while (K--) {
      int X, Y;
      cin >> X >> Y;
      cin.ignore();

      if (X == N || Y == M) cout << "divisa" << endl;
      else if (X > N && Y > M) cout << "NE" << endl;
      else if (X < N && Y > M) cout << "NO" << endl;
      else if (X < N && Y < M) cout << "SO" << endl;
      else if (X > N && Y < M) cout << "SE" << endl;
    }
  }
  
  return 0;
}