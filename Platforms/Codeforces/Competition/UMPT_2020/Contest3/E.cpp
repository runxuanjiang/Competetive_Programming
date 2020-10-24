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
    int n, m;
    cin >> n >> m;

    vector<unordered_set<int>> edges(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a].insert(b);
    }

    

}