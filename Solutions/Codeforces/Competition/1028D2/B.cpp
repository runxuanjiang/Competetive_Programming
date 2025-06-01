//Competition #:
//Problem #: B
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 998244353;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ll expmod(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<ll> p(n), q(n);
        for (ll i = 0; i < n; ++i) {
            cin >> p[i];
        }
        for (ll i = 0; i < n; ++i) {
            cin >> q[i];
        }



        ll max_p = 0;
        ll max_p_index = 0;
        ll max_q = 0;
        ll max_q_index = 0;

        for (int i = 0; i < n; ++i) {
            if (p[i] > max_p) {
                max_p = p[i];
                max_p_index = i;
            }
            if (q[i] > max_q) {
                max_q = q[i];
                max_q_index = i;
            }

            ll res = 0;

            if (max_p > max_q) {
                res = expmod(2, max_p);
                res += expmod(2, q[i - max_p_index]);
            }
            else if (max_q > max_p) {
                res = expmod(2, max_q);
                res += expmod(2, p[i - max_q_index]);
            }
            else {
                if (q[i-max_p_index] > p[i-max_q_index]) {
                    res = expmod(2, max_p);
                    res += expmod(2, q[i - max_p_index]);
                }
                else {
                    res = expmod(2, max_q);
                    res += expmod(2, p[i - max_q_index]);
                }
            }

            cout << (res % MOD) << " ";
        }
        cout << endl;


    }
}