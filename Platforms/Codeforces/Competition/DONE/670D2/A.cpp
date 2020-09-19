//Competition #: 670 D2
//Problem #: A
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
    tests{
        int n;
        cin >> n;
        unordered_map<int, int> counts;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (counts.find(a) == counts.end()) counts[a] = 1;
            else ++counts[a];
        }

        int res1 = 0, res2 = 0;
        for (int i = 0; i < n; ++i) {
            if (counts.find(i) != counts.end() && counts[i] >= 2) ++res1;
            else break;
        }
        for (int i = 0; i < n; ++i) {
            if (counts.find(i) != counts.end() && counts[i] >= 1) ++res2;
            else break;
        }
        cout << res1 + res2 << endl;
    }
}