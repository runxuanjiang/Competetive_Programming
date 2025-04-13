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

const unordered_set<ll> cycle_elements = {2, 4, 6, 8};

ll search_maximum(ll s, ll k) {
    ll res = s*k;
    ll l = 0, r = k/4;
    while (l <= r) {
        ll m = l + (r-l)/2;

        ll m_discount = (s + 20*m) * (k - 4*m);
        ll next_m_discount = (s + 20 * (m+1)) * (k - 4*(m+1));
        res = max(res, m_discount);
        if (m*4 >= k || m_discount > next_m_discount) {
            r = m-1;
        }
        else {
            l = m+1;
        }
    }
    
    return res;
}

int main() {
    fast;
    tests {
        ll s, k;
        cin >> s >> k;

        if (s % 10 == 0) {
            cout << k * s << endl;
        }
        else if (s % 10 == 5) {
            cout << max(k*s, (k-1)*(s+5)) << endl;
        }
        else {
            ll res = k*s;
            ll cycle_count = 0;
            for (ll i = 1; i <= k; ++i) {
                s = s + (s % 10);

                if (cycle_elements.find(s % 10) != cycle_elements.end()) {
                    cycle_count++;
                    res = max(res, search_maximum(s, k-i));
                }
                else {
                    res = max(res, s * (k-i));
                }

                if (cycle_count == 4) {
                    break;
                }

            }
            cout << res << endl;
        }


    }
}