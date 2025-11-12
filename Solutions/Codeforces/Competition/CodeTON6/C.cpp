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
        ll n, k; 
        cin >> n >> k;

        vector<ll> a(n);
        for (ll &i : a) cin >> i;

        vector<bool> used(n, false);
        ll lb = 0, ub = n-1;

        vector<ll> indices(n, 0);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&a](const ll &l, const ll &r) {
            return a[l] < a[r];
        });

        vector<ll> res(k+1, 0);

        for (auto i : indices) {
            while (used[lb]) {
                ++lb;
            }
            while (used[ub]) {
                --ub;
            }

            if (res[a[i]] == 0) {
                res[a[i]] = (ub-lb+1)*2;
            }
            used[i] = true;
            
        }
        for (int i = 1; i <=k; ++i) {
            cout << res[i] << " ";
        }
        cout << endl;

        

    }
}