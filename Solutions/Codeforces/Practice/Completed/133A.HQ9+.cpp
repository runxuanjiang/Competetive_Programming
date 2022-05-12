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

int main() {
    fast;
    string p;
    cin >> p;

    for (auto i : p) {
        if (i == 'H' || i == 'Q' || i == '9') {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}