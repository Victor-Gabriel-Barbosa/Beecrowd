#include <iostream>
using namespace std;

#define senhaCorreta 2002

int main() {
  int senha;

  do {
    cin >> senha;
    cin.ignore();

    if (senha == senhaCorreta) {
      cout << "Acesso Permitido" << endl;
      continue;
    } else cout << "Senha Invalida" << endl;
  } while (senha != senhaCorreta);

  return 0;
}