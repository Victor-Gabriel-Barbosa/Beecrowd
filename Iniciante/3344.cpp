#include <bits/stdc++.h>
using namespace std;

// Converte um número para sua representação por extenso em inglês
string numeroParaExtenso(int num) {
  const vector<string> unidades = {
    "ZERO",    "ONE",     "TWO",       "THREE",    "FOUR",
    "FIVE",    "SIX",     "SEVEN",     "EIGHT",    "NINE",
    "TEN",     "ELEVEN",  "TWELVE",    "THIRTEEN", "FOURTEEN",
    "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"
  };

  const vector<string> dezenas = {
    "TWENTY", "THIRTY", "FORTY",  
    "FIFTY",  "SIXTY",  "SEVENTY",
    "EIGHTY", "NINETY", "HUNDRED"
  };

  string resultado = "";

  if (num >= 20) {
    resultado += dezenas[(num / 10) - 2];
    if (num % 10 > 0) resultado += " " + unidades[num % 10];
  } else resultado += unidades[num];

  return resultado;
}

// Função f: retorna o número de caracteres do número escrito por extenso
int f(int x) {
  string extenso = numeroParaExtenso(x);
  return extenso.length();
}

int main() {
  int X;
  cin >> X;

  int resultado = X;

  // Realiza 1000 iterações da função f
  for (int i = 0; i < 1000; i++) resultado = f(resultado);

  cout << resultado << endl;

  return 0;
}