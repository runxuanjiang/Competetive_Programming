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


ll convert(ll i) {
    ll res = 1;
    for (int j = 0; j < i; ++j) {
        res *= 10;
    }
    return res;
}

int main() {
    fast;
    tests {
        string s;
        cin >> s;

        vector<ll> suffixMax(s.size(), 0);
        ll res = 0;
        for (int i = s.size() - 1; i > 0; --i) {
            if (suffixMax[i] > s[i] - 'A') {
                res -= convert(s[i] - 'A');
            }
            else {
                res += convert(s[i] - 'A');
            }
            // cerr << "current res is " << res << endl;
            suffixMax[i-1] = max(suffixMax[i], (ll) s[i] - 'A');
        }
        if (suffixMax[0] > s[0] - 'A') {
            res -= convert(s[0] - 'A');
        }
        else {
            res += convert(s[0] - 'A');
        }

        cerr << "res is " << res << endl;

        vector<ll> count(5, 0);




        ll maxDelta = 0;
        for (int idx = 0; idx < s.size(); ++idx) {
            ll i = s[idx] - 'A';
            for (ll j = 0; j < 5; ++j) {
                ll delta = 0;

                // back out existing for i
                if (suffixMax[idx] > i) {
                    delta += convert(i);
                }
                else {
                    delta -= convert(i);
                }

                // add in new for j
                if (suffixMax[idx] > j) {
                    delta -= convert(j);
                }
                else {
                    delta += convert(j);
                }

                for (int k = 0; k < 5; ++k) {
                    if (k >= suffixMax[idx]) {
                        if (k < i && k >= j) {
                            delta += convert(k) * count[k] * 2;
                        }
                        else if (k >= i && k < j) {
                            delta -= convert(k) * count[k] * 2;
                        }
                    }
                }

                maxDelta = max(maxDelta, delta);
            }

            ++count[i];
            for (ll j = 0; j < i; ++j) {
                count[j] = 0;
            } 
        }

        cerr << "maxDelta is " << maxDelta << endl;

        cout << res + maxDelta << endl;

    }
}