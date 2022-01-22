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

ld recurse(int n, int p, const vector<unordered_set<int>> &graph) {
    ld tot = 0;
    ld cnt = 0;
    for (auto c : graph[n]) {
        if (c != p) {
            cnt += 1;
            tot += recurse(c, n, graph) + 1;
        }
    }

    if (cnt > 0) {
        return (tot / cnt);
    }
    else {
        return (ld) 0;
    }
}

int main() {
    fast;
    int n;
    cin >> n;
    vector<unordered_set<int>> graph(n);
    for (int i = 0; i+1 < n; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a-1].insert(b-1);
        graph[b-1].insert(a-1);
    }
    cout << setprecision(10);
    cout << recurse(0, -1, graph) << endl;


}