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
        ll n;
        cin >> n;

        int a = 0;
        int b = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == a || j == b) cout << 1 << " ";
                else cout << 0 << " ";
            }
            a += 1;
            b += 1;
            if (a >= n) a = 0;
            if (b >= n) b = 0;
            cout << endl;
        }
    }
}