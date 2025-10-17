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
        ll n, a, q;
        cin >> n >> a >> q;


        string s;
        cin >> s;

        ll max_s = a;
        ll max_possible_s = a;

        for (auto i : s) {
            if (i == '+') {
                ++max_possible_s;
                ++a;
                max_s = max(a, max_s);
            }
            else {
                --a;
            }
        }

        if (max_possible_s < n) {
            cout << "NO\n";
        }
        else if (max_s == n) {
            cout << "YES\n";
        }
        else {
            cout << "MAYBE\n";
        }
    }
}