//Competition #:
//Problem #: D
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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> parent[n];
    for (int i = 0; i < m; ++i) {
        int first, second;
        cin >> first >> second;
        parent[second-1].push_back(first-1);
    }

    unordered_map<int, int> dp;
    queue<int> q;
    q.push(1);
    dp[1] = 0;
    int end = 0;
    for (int i = 0; i < k+2; ++i) {
        end |= (1 << i);
    }


    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if ((current & end) == end) {
            cout << dp[current] << '\n';
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            if (current & (1 << i)) {
                for (auto j : parent[i]) {
                    if (!(current & (1 << j))) {
                        int add = current;
                        add |= (1 << j);
                        if (dp.find(add) == dp.end()) {
                            dp[add] = dp[current] + 1;
                            q.push(add);
                        }
                        else {
                            dp[add] = min(dp[add], dp[current] + 1);
                        }
                    }
                }
            }
        }
    }
}