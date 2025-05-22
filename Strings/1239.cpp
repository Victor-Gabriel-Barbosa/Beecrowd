#include <bits/stdc++.h>
using namespace std;

int main() {
  string html;
  
  while (getline(cin, html)) {
    string html2;
    bool dentroI = false, dentroB = false;

    for (char c : html) {
      if (c == '_') {
        if (dentroI) {
          html2 += "</i>";
          dentroI = false;
        } else {
          html2 += "<i>";
          dentroI = true;
        }
      } else if (c == '*') {
        if (dentroB) {
          html2 += "</b>";
          dentroB = false;
        } else {
          html2 += "<b>";
          dentroB = true;
        }
      } else html2 += c;
    }

    cout << html2 << endl;
  }

  return 0;
}