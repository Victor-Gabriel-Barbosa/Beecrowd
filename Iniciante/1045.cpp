#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  vector<double> abc(3);
  
  for (int i = 0; i < 3; i++) cin >> abc[i];
  sort(abc.begin(), abc.end(), greater<double>());
  if (abc[0] >= abc[1] + abc[2]) cout << "NAO FORMA TRIANGULO" << endl;
  else {
    if (abc[0] > abc[1] + abc[2]) cout << "TRIANGULO ACUTANGULO" << endl;
    if (pow(abc[0], 2) == pow(abc[1], 2) + pow(abc[2], 2)) cout << "TRIANGULO RETANGULO" << endl;
    if (pow(abc[0], 2) > pow(abc[1], 2) + pow(abc[2], 2)) cout << "TRIANGULO OBTUSANGULO" << endl;
    if (pow(abc[0], 2) < pow(abc[1], 2) + pow(abc[2], 2)) cout << "TRIANGULO ACUTANGULO" << endl;
    if (abc[0] == abc[1] && abc[1] == abc[2]) cout << "TRIANGULO EQUILATERO" << endl;
    if ((abc[0] == abc[1] && abc[1] != abc[2]) || (abc[0] != abc[1] && abc[1] == abc[2])) cout << "TRIANGULO ISOSCELES" << endl;
  }
  
  return 0;
}