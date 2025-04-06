#include <iostream>
#include <map>
using namespace std;

int main() {
  int N, total;
  string numLed;

  cin >> N;
  map<char, int> ledMap = {
      {'0', 6}, {'1', 2}, {'2', 5}, {'3', 5}, {'4', 4},
      {'5', 5}, {'6', 6}, {'7', 3}, {'8', 7}, {'9', 6}};
    
  while (N--) {
    cin >> numLed;
    total = 0;
    for (char num : numLed) total += ledMap[num];
    cout << total << " leds" << endl;
  }  

  return 0;
}