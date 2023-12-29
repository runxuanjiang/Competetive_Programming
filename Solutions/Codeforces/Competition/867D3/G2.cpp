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

            if (num > 1000000) {
                for (ll j = 2; j <= 1000; ++j) {
                    if (num % j == 0 && counts.find(num/j) != counts.end() && counts.find(num*j) != counts.end()) {
                        res += counts[num/j] * count * counts[num*j];
                    }
                }
            }
            else {
                for (ll j = 1; j * j <= num; ++j) {
                    if (num % j == 0) {
                        if (j > 1 && counts.find(num/j) != counts.end() && counts.find(num*j) != counts.end()) {
                            res += counts[num/j] * count * counts[num*j];
                        }
                        ll mult = num / j;
                        if (mult != j && counts.find(num/mult) != counts.end() && counts.find(num*mult) != counts.end()) {
                            res += counts[num/mult] * count * counts[num*mult];
                        }
                    }
                }
            }
        }

        cout << res << endl;


    }
}