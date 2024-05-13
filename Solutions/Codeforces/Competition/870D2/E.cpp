//Competition #:
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    size_t n, m;
    cin >> m >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    bitset<5000> allset;
    allset.set();
    vector<bitset<5000>> mat(n, allset);
    vector<size_t> indices(n);
    iota(indices.begin(), indices.end(), 0);

    bitset<5000> curr;
    for (size_t _ = 0; _ < m; ++_) {
        vector<size_t> ratings(n);
        for (size_t i = 0; i < n; ++i) {
            cin >> ratings[i];
        }

        curr.reset();

        sort(indices.begin(), indices.end(), [&](const size_t &a, const size_t &b) {return ratings[a] < ratings[b];});

        for (size_t i = 0; i < n; ++i) {
            mat[indices[i]] &= curr;
            size_t j = i;
            while (j+1 < n && ratings[indices[j+1]] == ratings[indices[i]]) {
                ++j;
                mat[indices[j]] &= curr;
            }
            for (size_t k = i; k <= j; ++k) {
                curr[indices[k]] = 1;
            }
            i = j;
        }
    }

    ll res = 0;
    vector<ll> dp = p;
    for (auto i : indices) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j]) {
                dp[i] = max(dp[i], p[i] + dp[j]);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << '\n';


}