//Competition #:
//Problem #: E
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
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;


        vector<int> free;
        int good = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                ++good;
            }
            else {
                good -= k;
                if (good > 0) {
                    free.push_back(good);
                }
                good = -k;
            }
        }

        if (good > 0) {
            free.push_back(good);
        }

        ll res = 0;
        for (auto f : free) {
            if (f % (k+1)) ++res; 
            res += (f/(k+1));
        }
        cout << res << endl;
    }
}