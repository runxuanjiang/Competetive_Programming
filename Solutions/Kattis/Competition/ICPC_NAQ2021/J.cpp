//Competition #:
//Problem #: I
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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    string res = "";
    ll plus = 0;
    while (a.size()) {
        a.back() += plus;
        while (a.back() > 1) {
            if (a.back() % 2) {
                ++plus;
                res += "+1";
                --a.back();
            }
            else {
                ++plus;
                res += "+d";
                a.back() /= 2;
            }
        }
        res += "1";
        a.pop_back();

    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}