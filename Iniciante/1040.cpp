#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double n1, n2, n3, n4, m, n;

  cin >> n1 >> n2 >> n3 >> n4;
  m = (n1 * 2 + n2 * 3 + n3 * 4 + n4 * 1) / 10;
  cout << "Media: " << fixed << setprecision(1) << m << endl;

  if (m >= 5.00 && m < 7.00) {
    cout << "Aluno em exame." << endl;
    cin >> n;
    cout << "Nota do exame: " << fixed << setprecision(1) << n << endl;
    m = (m + n) / 2;
    cout << "Aluno " << ((m >= 7.0) ? "aprovado" : "reprovado") << "." << endl;
    cout << "Media final: " << fixed << setprecision(1) << m << endl;
  } else cout << "Aluno " << ((m >= 7.0) ? "aprovado" : "reprovado") << "." << endl;

  return 0;
}