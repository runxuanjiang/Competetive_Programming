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

ll nxt(ll curr, ll n) {
    if (curr % 2) {
        return (curr + 1)/2;
    }
    else {
        return n/2 + (curr / 2);
    }
}

int main() {
    fast;
    tests {
        ll n, k;
        cin >> n >> k;

        vector<ll> res(n+1);
        vector<bool> seen(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            if (!seen[i]) {
                ll curr = i;
                vector<ll> graph;
                while (!seen[curr]) {
                    graph.push_back(curr);
                    seen[curr] = true;
                    curr = nxt(curr, n);
                }

                for (int j = 0; j < graph.size(); ++j) {
                    res[graph[(j + k) % graph.size()]] = graph[j];
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}