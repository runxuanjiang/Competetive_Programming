//Competition #:
//Problem #: E
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
    ll n;
    cin >> n;

    vector<ll> nodesets;
    vector<ll> nodesetsize;
    for (ll i = 2; i * (i-1)/2 <= n; ++i) {
        nodesets.push_back(i*(i-1)/2);
        nodesetsize.push_back(i);
    }

    vector<ll> dp(n+1);
    for (int i = 0; i <= n; ++i) {
        dp[i] = 2*i;
    }
    for (int i = 0; i < nodesets.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            if (j + nodesets[i] > n) {
                break;
            }

            dp[j + nodesets[i]] = min(dp[j+nodesets[i]], dp[j] + nodesetsize[i]);
        }
    }

    vector<ll> nodes;
    ll curr = n;
    ll total = 0;
    while (curr) {
        ll currmin = 2 + dp[curr-1];
        ll currminidx = 0;
        for (int i = 0; i < nodesets.size(); ++i) {
            if (nodesets[i] > curr) {
                break;
            }
            if (nodesetsize[i] + dp[curr-nodesets[i]] <= currmin) {
                currmin = nodesetsize[i] + dp[curr-nodesets[i]];
                currminidx = i;
            }
            
        }
        nodes.push_back(nodesetsize[currminidx]);
        total += nodesetsize[currminidx];
        curr -= nodesets[currminidx];
    }

    sort(nodes.begin(), nodes.end());

    ll res1 = total;
    ll res2 = 0;
    for (auto i : nodes) {
        total -= i;
        res2 += i * total;
    }

    cout << res1 << " " << res2 << endl;



}