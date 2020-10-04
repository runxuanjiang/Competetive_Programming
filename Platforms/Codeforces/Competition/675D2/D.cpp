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

int main() {
    fast;
    ll n, m;
    cin >> n >> m;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    pair<int, int> start = {a, b}, end = {c, d};

    unordered_map<int, vector<int>> x, y;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        x[a].push_back(b);
        y[b].push_back(a);
    }

    unordered_set<pair<int, int>> visited;

    queue<pair<int, pair<int, int>>> bfs;
    bfs.push({0, start});
    while (!bfs.empty()) {
        auto loc = bfs.front();
        bfs.pop();
        for (auto xcoord : x[loc.second.first]) {
            if ()
        }

    }
    
}