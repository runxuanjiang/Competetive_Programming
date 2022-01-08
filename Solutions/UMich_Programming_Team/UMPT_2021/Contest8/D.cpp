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
    tests {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int l = 0, r = n-1;
        bool done  = false;
        while (l < r) {
            if (abs((int) s[l] - (int) s[r]) != 2 && abs((int) s[l] - (int) s[r]) != 0) {
                cout << "NO" << endl;
                done = true;
                break;
            }
            ++l;
            --r;
        }
        if (!done) {
            cout << "YES" << endl;
        }

    }
}