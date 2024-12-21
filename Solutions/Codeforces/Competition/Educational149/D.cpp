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
    tests {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        ll curr = 0;
        ll dir = 0;
        ll count = 1;

        vector<ll> res;
        res.reserve(n);

        
        for (auto i : s) {
            if (i == '(') {
                ++curr;
            }
            else {
                --curr;
            }

            if (curr != 0) {
                if (dir == 0) {
                    dir = (curr > 0) ? 1 : -1;
                }
                else if ((dir > 0 && curr < 0) || (dir < 0 && curr > 0)) {
                    ++count;
                    dir = (curr > 0) ? 1 : -1;
                }
            }
            res.push_back(count);
        }

        if (curr) {
            cout << -1 << endl;
        }
        else {
            cout << min(count, 2ll) << endl;
            for (auto i : res) {
                cout << ((i%2) ? 1 : 2) << " ";
            }
            cout << endl;
        }

    }
}