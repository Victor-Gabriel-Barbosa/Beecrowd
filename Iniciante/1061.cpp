#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  string temp;
  int DI, HI, MI, SI, DF, HF, MF, SF;

  cin >> temp >> DI;
  cin >> HI >> temp >> MI >> temp >> SI;
  cin >> temp >> DF;
  cin >> HF >> temp >> MF >> temp >> SF;

  int STI = (DI * 24 * 3600) + (HI * 3600) + (MI * 60) + SI;
  int STF = (DF * 24 * 3600) + (HF * 3600) + (MF * 60) + SF;

  int DFT = STF - STI;

  int DT = DFT / (24 * 3600);
  DFT = DFT % (24 * 3600);
  int HT = DFT / 3600;
  DFT = DFT % 3600;
  int MT = DFT / 60;
  int ST = DFT % 60;

  cout << DT << " dia(s)" << endl;
  cout << HT << " hora(s)" << endl;
  cout << MT << " minuto(s)" << endl;
  cout << ST << " segundo(s)" << endl;

  return 0;
}