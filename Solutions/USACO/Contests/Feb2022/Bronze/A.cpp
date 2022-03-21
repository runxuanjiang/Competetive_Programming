//Competition #:
//Problem #: A
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

bool check(const vector<ll> &a, ll targ) {
    ll curr = 0;
    for (auto i : a) {
        curr += i;
        if (curr == targ) {
            curr = 0;
        }
        else if (curr > targ) {
            return false;
        }
    }
    return (!curr);
}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        
        ll res = n-1;
        for (int i = 1; i <= n; ++i) {
            if (sum % i == 0) {
                if (check(a, sum / i)) {
                    res = (n - i);
                }
            }
        }

        cout << res << endl;




    }
}