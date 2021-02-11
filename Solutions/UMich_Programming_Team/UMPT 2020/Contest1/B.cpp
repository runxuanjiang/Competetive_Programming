//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

bool test(string s) {
    unordered_set<char> seen;
    for (auto i : s) {
        if (seen.find(i) != seen.end()) return false;
        seen.insert(i);
    }
    return true;
}

int main() {
    fast;
    ll l, r;
    cin >> l >> r;
    bool found = false;
    for (ll i = l; i <= r; ++i) {
        if (test(to_string(i))) {
            cout << i;
            found = true;
            break;
        }
    }
    if (!found) cout << -1;
}