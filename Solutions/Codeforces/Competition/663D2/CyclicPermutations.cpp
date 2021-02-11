#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    unsigned long long mod = 1000000007;
    unsigned long long tot = 1;
    unsigned long long sub = 1;
    for (int i = 0; i < n; ++i) {
        tot = (tot * (i+1)) % mod;
        if (i > 0) sub  = (sub*2) % mod;
    }
    cout << (tot + mod - sub) % mod;
}