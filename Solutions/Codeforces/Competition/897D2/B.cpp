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
        ll n;
        cin >> n;
        string s;
        cin >> s;


        ll matched = 0, unmatched = 0, shared = 0, new_unmatched = 0;
        for (int i = 0; i < n; ++i) {
            ll other_i = n-i-1;
            if (i == other_i) {
                ++shared;
            }
            else if (s[i] == s[other_i]) {
                ++matched;
            }
            else {
                ++unmatched;
            }
        }

        for (int i = 0; i <= n; ++i) {
            if (unmatched == 0 && (matched % 2 == 0 || shared) && new_unmatched == 0) {
                cout << 1;
            }
            else {
                cout << 0;
            }
            if (unmatched > 0) {
                unmatched -= 2;
            }
            else if (shared > 0) {
                if (matched > 0) {
                    --matched;
                }
                else {
                    --shared;
                }
            }
            else if (matched > 0) {
                --matched;
            }
            else {
                new_unmatched++;
            }
        }
        cout << endl;
    }
}