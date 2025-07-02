#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, t;

    cin >> t;

    while (t--) {
        cin >> n >> m;

        int res = (n - m) * n;
        res = n * (n - 1) / 2;
        cout << res << endl;
    }

    return 0;
}