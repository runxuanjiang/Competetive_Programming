#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; ++x) {
        long long p, f;
        cin >> p >> f;
        long long sw, wa;
        cin >> sw >> wa;
        long long w1, w2;
        cin >> w1 >> w2;

        if (w2 < w1) {
            swap(w1, w2);
            swap(sw, wa);
        }

        long long tot = p+f;
        long long res = 0;
        res += min(sw, tot / w1);
        tot -= (w1*res);
        res += min(wa, tot/w2);
        cout << res << endl;
        
    }
}