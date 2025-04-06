#include <cmath>
#include <iostream>

using namespace std;

// Calcula o MDC (Máximo Divisor Comum)
int MDC(int a, int b) {
  a = abs(a);
  b = abs(b);

  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }

  return a;
}

// Estrutura para representar um número racional
struct Racional {
  int numerador;
  int denominador;

  // Simplifica a fração
  void simplificar() {
    int divisor = MDC(numerador, denominador);
    numerador /= divisor;
    denominador /= divisor;

    // Se o denominador for negativo, ajustar os sinais
    if (denominador < 0) {
      numerador = -numerador;
      denominador = -denominador;
    }
  }

  // Imprime a fração
  void print() { 
    cout << numerador << "/" << denominador; 
  }
};

// Realiza as operações entre dois números racionais
Racional resolverOp(Racional r1, Racional r2, char op) {
  Racional resposta;

  switch (op) {
  case '+': // Soma: (N1*D2 + N2*D1) / (D1*D2)
    resposta.numerador = r1.numerador * r2.denominador + r2.numerador * r1.denominador;
    resposta.denominador = r1.denominador * r2.denominador;
    break;

  case '-': // Subtração: (N1*D2 - N2*D1) / (D1*D2)
    resposta.numerador = r1.numerador * r2.denominador - r2.numerador * r1.denominador;
    resposta.denominador = r1.denominador * r2.denominador;
    break;

  case '*': // Multiplicação: (N1*N2) / (D1*D2)
    resposta.numerador = r1.numerador * r2.numerador;
    resposta.denominador = r1.denominador * r2.denominador;
    break;

  case '/': // Divisão: (N1*D2) / (N2*D1)
    resposta.numerador = r1.numerador * r2.denominador;
    resposta.denominador = r1.denominador * r2.numerador;
    break;
  }

  return resposta;
}

int main() {
  int N;
  cin >> N; 

  for (int i = 0; i < N; i++) {
    // Lê a expressão no formato: N1 / D1 op N2 / D2
    Racional r1, r2, resposta, simplificado;
    char barra1, op, barra2;

    cin >> r1.numerador >> barra1 >> r1.denominador >> op >> r2.numerador >> barra2 >> r2.denominador;

    // Realiza a operação
    resposta = resolverOp(r1, r2, op);

    // Cria uma cópia para simplificar
    simplificado = resposta;
    simplificado.simplificar();

    // Imprime o resultado
    resposta.print();
    cout << " = ";
    simplificado.print();
    cout << endl;
  }

  return 0;
}