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

int testnum = 0;


int main() {
    fast;
    tests {
        ++testnum;
        cout << "Case #" << testnum << ": ";

        // read in input
        int n, k;
        cin >> n >> k;
        vector<vector<int>> graph(n);
        vector<ll> gold(n);
        for (int i = 0; i < n; ++i) {
            cin >> gold[i];
        }
        for (int i = 0; i < n-1; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }

        int res = gold[0];
        if (k == 0) {
            return res;
        }

        vector<pair<int, int>> subTrees; // {total sum of subtree, parent}
        

        // find the total sum of each child:
        



    }
}