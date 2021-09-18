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

ll testnum = 0;
int n, m;

ll recurse(bitset<16> mask, ll score, const vector<vector<ll>> &rooms, const vector<vector<int>> &graph, vector<unordered_map<ll, ll>> &dp, const int &k) {
    ll bm = (long long) (mask.to_ulong());
    if (dp[bm].find(score) != dp[bm].end()) {
        return dp[bm][score];
    }
    if (score > k) {
        return 0;
    }

    if (score == k) {
        dp[bm][score] = 1;
    }
    else {
        ll res = 0;
        bitset<16> checked(0);
        for (int i = 0; i < n; ++i) {
            if (mask[i]) {
                for (auto child : graph[i]) {
                    if (!mask[child] && score >= rooms[child][0] && score <= rooms[child][1] && !checked[child]) {
                        checked[child] = 1;
                        mask[child] = 1;
                        res += recurse(mask, score + rooms[child][2], rooms, graph, dp, k);
                        mask[child] = 0;
                    }
                }
            }
        }
        dp[bm][score] = res;
    }

    return dp[bm][score];
}

int main() {
    fast;
    tests {
        ++testnum;
        cout << "Case #" << testnum << ": ";

        cin >> n >> m;
        ll k;
        cin >> k;
        vector<vector<ll>> rooms(n);
        for (int i = 0; i < n; ++i) {
            ll l, r, a;
            cin >> l >> r >> a;
            rooms[i] = {l, r, a};
        }

        vector<vector<int>> graph(n);
        for (int i = 0; i < m; ++i) {
            int l, r;
            cin >> l >> r;
            graph[l].push_back(r);
            graph[r].push_back(l);
        }

        ll sz = 1 << (n+1);
        vector<unordered_map<ll, ll>> dp(sz);
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            bitset<16> mask(0);
            mask[i] = 1;
            res += recurse(mask, rooms[i][2], rooms, graph, dp, k);
        }

        cout << res << endl;
    }

}