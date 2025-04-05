#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
private:
  int MHT;
  vector<list<int>> HT;

public:
  HashTable(int size) : MHT(size) {
    HT.resize(MHT);
  }

  int hash(int CHVHT) {
    return CHVHT % MHT;
  }

  void push(int CHVHT) {
    int PSI = hash(CHVHT);
    HT[PSI].push_back(CHVHT);
  }

  void print() {
    for (int i = 0; i < MHT; i++) {
      cout << i;
      for (int CHVHT : HT[i]) cout << " -> " << CHVHT;
      cout << " -> \\" << endl;
    }
  }
};

int main() {
  int NET; 
  cin >> NET;
  for (int NCS = 0; NCS < NET; NCS++) {
    int MHT, CHV;
    cin >> MHT >> CHV;
    HashTable hash(MHT);
    for (int i = 0; i < CHV; i++) {
      int CHVHT;
      cin >> CHVHT;
      hash.push(CHVHT);
    }
    hash.print();
    if (NCS < NET - 1) cout << endl;
  }
  return 0;
}