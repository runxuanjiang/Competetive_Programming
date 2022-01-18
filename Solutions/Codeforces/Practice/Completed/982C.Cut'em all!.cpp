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

int recurse(int node, int parent, const vector<unordered_set<int>> &graph, int &res) {

    int children = 1;
    for (auto child : graph[node]) {
        if (child != parent) {
            int tempchildren = recurse(child, node, graph, res);
            if (tempchildren % 2 == 0) {
                ++res;
            }
            children += tempchildren;
        }
    }

    return children;

}

int main() {
    fast;
    int n;
    cin >> n;
    vector<unordered_set<int>> graph(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a-1].insert(b-1);
        graph[b-1].insert(a-1);
    }

    if (n % 2) {
        cout << -1 << endl;
        return 0;
    }

    int res = 0;
    recurse(0, -1, graph, res);
    cout << res << endl;

}