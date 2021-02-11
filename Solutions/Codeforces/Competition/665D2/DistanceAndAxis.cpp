#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; ++x) {
        int n, k;
        cin >> n >> k;
        if (k >= n) cout << k - n << endl;
        else cout << (n%2 != k%2) << endl;
    }
}