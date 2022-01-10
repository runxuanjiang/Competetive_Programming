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
    tests {
        string s;
        cin >> s;
        bool found = false;
        for (int i = 0; i+1 < s.size(); ++i) {
            if (s[i] == '1') {
                cout << "yes" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "no" << endl;
        }
    }
}