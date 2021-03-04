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

int main() {
    fast;
    tests {
        int N, M;
        cin >> N >> M;
        vector<unordered_multimap<int, int>> graph(N);
        for (int i = 0; i < M; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a-1].insert({b-1, c});
            graph[b-1].insert({a-1, c});
        }

        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].size() == 2) {
                int dist = 0, s1 = -1, s2 = -1;
                for (auto station : graph[i]) {
                    dist += station.second;
                    if (s1 == -1) {
                        s1 = station.first;
                    }
                    else {
                        s2 = station.first;
                    }
                }

                if (s1 == s2) {
                    graph[s1].insert({s2, dist});
                }
                else {
                    graph[s1].insert({s2, dist});
                    graph[s2].insert({s1, dist});
                }
                graph[i] = {};
                graph[s1].erase(i);
                graph[s2].erase(i);

                M-=1;

            }
        }

        cout << M << endl;

        for (int i = 0; i < graph.size(); ++i) {
            for (auto station : graph[i]) {
                if (station.first >= i) {
                    cout << i+1 << " " << station.first+1 << " " << station.second << endl;
                }
            }
        }
        cout << endl;
    }
}