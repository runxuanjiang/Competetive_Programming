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
        ll m, k, a_1, a_k;
        cin >> m >> k >> a_1 >> a_k;


        if (a_1 > k) {
            ll extra_k = (a_1 / k) - 1;
            a_k += extra_k;
            a_1 -= (extra_k * k);
        }

        ll k_used = min(a_k, m/k);
        m -= (k_used * k);


        ll res = (m%k) - min(a_1, m%k);
        a_1 -= min(a_1, m%k);
        m -= (m%k);

        ll a_1_k = a_1 / k;
        ll m_k = m / k;


        res += m_k - min(a_1_k, m_k);

        cout << res << endl;




    }
}