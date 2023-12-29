//Competition #:
//Problem #: G
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

        map<ll, ll> counts;
        for (auto i : a) {
            if (counts.find(i) == counts.end()) {
                counts[i] = 0;
            }
            counts[i]++;
        }

        ll res = 0;

        for (auto i : counts) {
            ll num = i.first;
            ll count = i.second;

            if (count >= 3) {
                res += (count * (count-1) * (count-2));
            }

            for (ll base = 2; base*base <= num; ++base) {
                if (num % (base*base) == 0 && counts.find(num / base) != counts.end() && counts.find(num / (base * base)) != counts.end()) {
                    res += counts[num/(base*base)] * counts[num/base] * count;
                }
            }
        }

        cout << res << endl;


    }
}