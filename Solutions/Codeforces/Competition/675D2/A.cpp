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
        vector<ll> sides(3);
        for (int i = 0; i < 3; ++i) {
            cin >> sides[i];
        }
        sort(sides.begin(), sides.end());
        if (sides[0] + sides[1] < sides[2]) {
            cout << sides[2] - sides[0] - sides[1] + 1 << endl;
        }
        else cout << 1 << endl;
    }
}