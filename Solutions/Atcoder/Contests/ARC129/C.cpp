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

vector<ll> mods = {1, 3, 2, 6, 4, 5};

int main() {
    fast;
    ll n;
    cin >> n;

    unordered_set<ll> seen = {0};

    ll curr = 1, plus = 1;
    vector<ll> tri;
    while (curr <= n) {
        tri.push_back(curr);
        plus++;
        curr += plus;
    }

    string res;
    for (int i = tri.size(); i > 0; i--) {
        while (n >= tri[i-1]) {
            n -= tri[i-1];
            res += string(i, '7');
            res += "1";
        }
    }
    res.pop_back();

    ll zeros = 0;
    curr = 0;
    for (int i = res.size() - 1; i >= 0; --i) {
        if (res[i] == '1') {
            ll md = mods[zeros % 6];
            for (ll j = 1; j <= 9; ++j) {
                if (seen.find((j * md + curr) % 7) == seen.end()) {
                    res[i] = ('0' + j);
                    curr = (j * md + curr) % 7;
                    seen.insert(curr);
                    break;
                }
            }
        }
        zeros++;
    }

    cout << res << endl;
}