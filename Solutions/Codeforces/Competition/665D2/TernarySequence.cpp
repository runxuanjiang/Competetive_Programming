#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; ++x) {
        long long x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        long long x2, y2, z2;
        cin >> x2 >> y2 >> z2;

        long long count = 0;
        long long pos = min(y2, z1);

        count += 2*pos;
        z1 -= pos;
        y2 -= pos;
        z2 -= (x1 + z1);
        if (z2 > 0) count -= 2*z2;
        cout << count << endl;
    }
}