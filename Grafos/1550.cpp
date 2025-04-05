#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int inverteDigitos(int num) {
  int invertido = 0;
  while (num > 0) {
    invertido = invertido * 10 + num % 10;
    num /= 10;
  }
  return invertido;
}

int numeroMinimoBotoes(int A, int B) {
  if (A == B) return 0;
  queue<pair<int, int>> fila; 
  unordered_set<int> visitados;
  fila.push({A, 0});
  visitados.insert(A);
  while (!fila.empty()) {
    int numero = fila.front().first;
    int operacoes = fila.front().second;
    fila.pop();
    int adicionar = numero + 1;
    if (adicionar == B) return operacoes + 1;
    if (visitados.find(adicionar) == visitados.end() && adicionar < 10000) {
      fila.push({adicionar, operacoes + 1});
      visitados.insert(adicionar);
    }
    int invertido = inverteDigitos(numero);
    if (invertido == B) return operacoes + 1;
    if (visitados.find(invertido) == visitados.end() && invertido < 10000) {
      fila.push({invertido, operacoes + 1});
      visitados.insert(invertido);
    }
  }
  return -1;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int A, B;
    cin >> A >> B;
    cout << numeroMinimoBotoes(A, B) << endl;
  }
  return 0;
}