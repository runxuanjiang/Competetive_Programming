//Competition #:
//Problem #: B
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
        ll q;
        cin >> q;

        vector<ll> a;
        bool dip = false;
        string res;
        for (int i = 0; i < q; ++i) {
            ll x;
            cin >> x;

            if (a.empty()) {
                a.push_back(x);
                res += "1";
            } else {
                if (dip) {
                    if (x >= a.back() && x <= a.front()) {
                        a.push_back(x);
                        res += "1";
                    } else {
                        res += "0";
                    }
                }
                else {
                    if (x >= a.back()) {
                        a.push_back(x);
                        res += "1";
                    }
                    else {
                        if (x <= a.front()) {
                            a.push_back(x);
                            res += "1";
                            dip = true;
                        } else {
                            res += "0";
                        }
                    }
                }
            }
        }

        cout << res << endl;
    }
}