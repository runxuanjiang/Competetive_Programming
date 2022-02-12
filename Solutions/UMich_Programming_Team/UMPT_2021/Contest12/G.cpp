//Competition #:
//Problem #: G
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

pair<ll, ll> recurse(int t, const vector<vector<int>> &graph, const vector<pair<pair<int, int>, ll>> &trails, unordered_map<int, unordered_map<int, int>> &edges, vector<pair<ll, ll>> &dp) {
    if (dp[t].first) {
        return dp[t];
    }

    dp[t] = {1, 1};
    int a = trails[t].first.first;
    int b = trails[t].first.second;
    ll len = trails[t].second;

    for (auto child : graph[a]) {
        if (trails[edges[a][child]].second > len) {
            pair<ll, ll> temp = recurse(edges[a][child], graph, trails, edges, dp);
            if (a == trails[edges[a][child]].first.first) {
                dp[t].second += temp.first;
            }
            else {
                dp[t].second += temp.second;
            }
        }
    }
    for (auto child : graph[b]) {
        if (trails[edges[b][child]].second > len) {
            pair<ll, ll> temp =  recurse(edges[b][child], graph, trails, edges, dp);
            if (b == trails[edges[b][child]].first.first) {
                dp[t].first += temp.first;
            }
            else {
                dp[t].first += temp.second;
            }
        }
    }

    return dp[t];
}

int main() {
    fast;
    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    vector<pair<pair<int, int>, ll>> trails(n-1);
    unordered_map<int, unordered_map<int, int>> edges;
    for (int i = 0; i+1 < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
        edges[a-1][b-1] = i;
        edges[b-1][a-1] = i;
        trails[i] = {{a-1, b-1}, c};
    }

    vector<pair<ll, ll>> dp(n-1, {0, 0});
    ll res = 0;
    for (int i = 0; i < n-1; ++i) {
        pair<ll, ll> temp = recurse(i, graph, trails, edges, dp);
        res += temp.first + temp.second;
    }

    cout << res << endl;
    
}