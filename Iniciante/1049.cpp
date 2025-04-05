#include <iostream>
using namespace std;

int main() {
  string vertebra, filo, alimentacao, animal;

  cin >> vertebra >> filo >> alimentacao;
  if (vertebra == "vertebrado") {
    if (filo == "ave") animal = (alimentacao == "carnivoro") ? "aguia" : "pomba";
    else animal = (alimentacao == "onivoro") ? "homem" : "vaca";
  } else {
    if (filo == "inseto") animal = (alimentacao == "hematofago") ? "pulga" : "lagarta";
    else animal = (alimentacao == "hematofago") ? "sanguessuga" : "minhoca";
  }

  cout << animal << endl;
  
  return 0;
}