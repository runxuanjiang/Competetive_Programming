//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int testnum = 0;

int main() {
    fast;
    tests {
        ++testnum;
        cout << "Case #" << testnum << ": ";
        ll n;
        string s;
        cin >> n;
        cin >> s;

        ll res = 0;
        vector<ll> lefts, rights;

        char curr = '.';
        ll l = 0;
        ll lastChar = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != 'F') {
                if (s[i] == curr || curr == '.') {
                    curr = s[i];
                    lastChar = i;
                }
                else {
                    lefts.push_back(lastChar - l + 1);
                    l = lastChar + 1;
                    lastChar = i;
                    curr = s[i];
                }
            }
        }
        lefts.push_back(lastChar - l + 1);

        l = 0;
        curr = '.';
        for (int i = 0; i < n; ++i) {
            if (s[i] != 'F') {
                if (curr == '.') {
                    curr = s[i];
                    l = i;
                }
                else if (s[i] != curr) {
                    rights.push_back(i - l);
                    l = i;
                    curr = s[i];
                }
            }
        }
        rights.push_back(n - l);

        if (lefts.size() == 1) {
            cout << 0 << endl;
            continue;
        }



        ll mult = 0;
        for (ll i = 1; i < rights.size(); ++i) {
            mult = (mult + (i * rights[i]) % MOD) % MOD;
        }

        vector<ll> sub;
        ll sum = 0;
        for (ll i = rights.size() - 1; i >= 1; --i) {
            sum = (sum + rights[i]) % MOD;
            sub.push_back(sum);
        }
        sub = vector<ll>(sub.rbegin(), sub.rend());

        for (int i = 0; i < lefts.size() - 1; ++i) {
            res = (res + (lefts[i] * mult) % MOD) % MOD;
            mult = (mult - sub[i] + 4*(ll) MOD) % MOD;
        }

        cout << res << endl;
    }
}