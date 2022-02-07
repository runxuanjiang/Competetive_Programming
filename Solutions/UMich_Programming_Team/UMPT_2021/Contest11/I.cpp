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

int n;
ll k;
int recurse(int state, ll m, const vector<ll> &a, vector<unordered_map<ll, int>> &dp) {
    bool done = true;
    for (int i = 0; i < n; ++i) {
        if (!(state & (1 << i))) {
            done = false;
            break;
        }
    }
    if (done) return 1;

    if (dp[state].find(m) != dp[state].end()) {
        return dp[state][m];
    }

    int res = n;

    for (int i = 0; i < n; ++i) {
        if (!(state & (1 << i))) {
            int nextstate = state;
            nextstate |= (1 << i);
            if (a[i] <= m) {
                res = min(res, recurse(nextstate, m-a[i], a, dp));
            }
            else {
                res = min(res, 1 + recurse(nextstate, k - a[i], a, dp));
            }
        }
    }

    dp[state][m] = res;
    return res;

}

int main() {
    fast;
    cin >> n;
    cin >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<unordered_map<ll, int>> dp((1 << (n+1)));

    cout << recurse(0, k, a, dp) << endl;
}