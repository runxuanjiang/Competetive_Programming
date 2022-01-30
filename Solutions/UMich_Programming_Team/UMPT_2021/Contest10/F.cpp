//Competition #:
//Problem #: F
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ll X, R, P;


int main() {
    fast;
    ll n;
    cin >> n;
    cin >> X >> R >> P;
    ll k;
    cin >> k;
    
    string regen;
    cin >> regen;

    vector<ll> poisons;
    ll res = X * n;


    for (ll i = 0; i < n; ++i) {
        if (regen[i] == '0') {
            poisons.push_back((ll) (n-i) * P);
        }
        else {
            res -= ((n- i) * R);
            poisons.push_back((n- i) * (P + R));
        }
    }

    sort(poisons.begin(), poisons.end(), greater<ll>());
    for (ll i = 0; i < k; ++i) {
        res += poisons[i];
    }

    cout << res << endl;

    



}