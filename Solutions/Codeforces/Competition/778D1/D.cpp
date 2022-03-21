//Competition #:
//Problem #: D
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 998244353;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        unordered_map<int, unordered_map<int, pair<ll, ll>>> edges;
        vector<unordered_set<int>> graph(n);
        vector<unordered_set<int>> parents(n);
        vector<ll> res(n, 1);
        for (int i = 0; i+1 < n; ++i) {
            int a, b;
            cin >> a >> b;
            ll x, y;
            cin >> x >> y;
            if (x > y) {
                swap(x, y);
                swap(a, b);
            }

            graph[a-1].insert(b-1);
            parents[b-1].insert(a-1);
            edges[a-1][b-1] = {x / gcd(x, y), y / gcd(x, y)};
            res[a-1] = lcm(res[a-1], x / gcd(x, y)) % MOD;
            res[b-1] = lcm(res[b-1], y / gcd(x, y)) % MOD;
        }

        queue<int> curr, next;
        for (int i = 0; i < n; ++i) {
            if (parents[i].empty()) {
                curr.push(i);
            }
        }

        while (!curr.empty()) {
            while (!curr.empty()) {
                int c = curr.front();
                curr.pop();
                for (auto child : graph[c]) {
                    ll from = edges[c][child].first;
                    ll base = edges[c][child].second;
                    for (auto gchild : graph[child]) {
                        res[c] = lcm(res[c], res[child] * from / base);
                        res[c] = (res[c] * ( edges[child][gchild].first / gcd(edges[child][gchild].first, res[c] * base / from))) % MOD;
                    }
                    res[child] = lcm(res[child], res[c] * base / from) % MOD;
                    
                    parents[child].erase(c);
                    if (parents[child].empty()) {
                        next.push(child);
                    }
                }
            }

            swap(curr, next);
            next = queue<int>();
        }

        ll ans = 0;
        for (auto i : res) {
            ans = (ans + i) % MOD;
        }

        for (auto i : res) {
            cout << i << " ";
        }
        cout << endl;

        cout << ans << endl;



    }
}