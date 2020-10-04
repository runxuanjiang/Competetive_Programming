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
    tests{
        int n, k;
        cin >> n >> k;

        vector<int> p(n);

        int min1 = MOD;
        int minid = 0;
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            if (p[i] < min1) {
                min1 = p[i];
                minid = i;
            }
        }

        int res = 0;

        for (int i = 0; i < n; ++i) {
            if (i != minid) {
                res += ((k - p[i]) / min1);
            }
        }

        
        cout << res << endl;
    }
}