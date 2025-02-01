//Competition #:
//Problem #: C
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
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (a.back() == 1) {
            cout << "NO" << endl;
        }
        else {
            ll count = 0;
            vector<ll> res;
            for (int i = 0; i < n; ++i) {
                if (a[i]) {
                    ++count;
                }
                else {
                    res.push_back(count);
                    for (int j = 0; j < count; ++j) {
                        res.push_back(0);
                    }
                    count = 0;
                }
            }

            cout << "YES" << endl;
            for (auto i = res.rbegin(); i != res.rend(); ++i) {
                cout << *i << " ";
            }
            cout << endl;
        }






    }
}