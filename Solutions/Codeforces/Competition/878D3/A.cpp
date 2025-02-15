//Competition #:
//Problem #: A
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
        ll n;
        cin >> n;
        string s;
        cin >> s;


        string res;
        
        char repeated = 0;
        for (int i = 0; i < n; ++i) {
            if (!repeated) {
                repeated = s[i];
            }
            else {
                if (s[i] == repeated) {
                    res.push_back(s[i]);
                    repeated = 0;
                }
            }
        }

        cout << res << endl;
    }
}