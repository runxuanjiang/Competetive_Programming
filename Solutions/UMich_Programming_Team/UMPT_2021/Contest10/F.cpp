//Competition #:
//Problem #: F
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int recurse(int node, int parent, const vector<vector<int>> &graph, int &res) {
    int cnt = 1;
    for (auto i : graph[node]) {
        if (i != parent) {
            int num = recurse(i, node, graph, res);
            if (num % 2 == 0) {
                ++res;
            }
            cnt += num;
        }
    }
    return cnt;
}

int main() {
    fast;
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i+1 < n; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    if (n%2) {
        cout << -1 << endl;
        return 0;
    }

    int res = 0;
    recurse(0, -1, graph, res);

    cout << res << endl;
}