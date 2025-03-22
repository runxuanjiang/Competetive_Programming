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

int main() {
    fast;
    tests {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        string rs(s.rbegin(), s.rend());

        // cerr << s << " " << rs << '\n';

        bool good = false;

        unordered_set<char> letters;

        for (int i = 0; i < n; ++i) {
            letters.insert(s[i]);
            if (s[i] < rs[i]) {
                good = true;
                break;
            }
            else if (rs[i] < s[i]) {
                if (k > 0) {
                    good = true;
                }
                break;

            }
        }

        if (letters.size() > 1 && k > 0) {
            good = true;
        }

        cout << (good ? "YES" : "NO") << '\n';
    }
}