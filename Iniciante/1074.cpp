#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore();

  while (N--) {
    int num;
    cin >> num;
    cin.ignore();

    if (num == 0) {
      cout << "NULL" << endl;
      continue;
    }

    cout << ((num % 2) ? "ODD" : "EVEN");
    cout << " " << ((num > 0) ? "POSITIVE" : "NEGATIVE") << endl;
  }

  return 0;
}