//Competition #:
//Problem #: D
//Accepted: 

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
    int n;
    cin >> n;
    ll m;
    cin >> m;

    vector<int> res(m+1, -1);
    res[0] = 0;

    int step = 1;
    for (int i = 0; i < n; ++i) {
        ll t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            ld base = (ld) x / (ld) 100000;
            for (int j = 0; j < m+1; ++j) {
                if (res[j] != -1 && res[j] != step) {
                    int newj = j;
                    for (int k = 1; k <= y; ++k) {
                        newj = ceil((ld) newj + base);
                        if (newj <= m && res[newj] == -1) {
                            res[newj] = step;
                        }
                    }
                }
            }
        }
        else if (t == 2) {
            ld base = (ld) x / (ld) 100000;
            for (int j = 0; j < m+1; ++j) {
                if (res[j] != -1 && res[j] != step) {
                    int newj = j;
                    for (int k = 1; k <= y; ++k) {
                        newj = ceil((ld) newj * base);
                        if (newj <= m && res[newj] == -1) {
                            res[newj] = step;
                        }
                    }
                }
            }
        }
        ++step;
    }

    for (int i = 1; i < m+1; ++i) {
        cout << res[i] << " ";
    }
    cout << '\n';


}