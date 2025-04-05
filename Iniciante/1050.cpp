#include <iostream>
#include <map>
using namespace std;

int main() {
  int ddd;
  map<int, string> ddds = {{61, "Brasilia"}, {71, "Salvador"}, {11, "Sao Paulo"}, {21, "Rio de Janeiro"}, 
                           {32, "Juiz de Fora"}, {19, "Campinas"}, {27, "Vitoria"}, {31, "Belo Horizonte"}};
                           
  cin >> ddd;
  cout << ((ddds.find(ddd) != ddds.end()) ? ddds[ddd] : "ddd nao cadastrado") << endl;

  return 0;
}