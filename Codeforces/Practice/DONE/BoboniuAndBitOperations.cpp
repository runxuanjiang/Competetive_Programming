//Competition #: UMPT 2020 Practice 9
//Problem #: G
//Accepted: Yes

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    ll n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int maximum = 1 << 9;
    for (int i = 0; i < maximum; ++i) {
        bool done = false;
        for (int j = 0; j < n; ++j) {
            bool found = false;
            for (int k = 0; k < m; ++k) {
                if (((a[j] & b[k]) | i) == i) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
            if (found && j == n-1) {
                done = true;
            }
        }
        if (done) {
            cout << i;
            break;
        }
    }
}