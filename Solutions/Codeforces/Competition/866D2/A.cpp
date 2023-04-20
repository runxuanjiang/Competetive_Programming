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
        string s;
        cin >> s;

        if (s == "^") {
            cout << 1 << endl;
            continue;
        }

        ll res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '_') {
                int j = i;
                while (j+1 < s.size() && s[j+1] == '_') {
                    ++j;
                }
                res += (j-i);
                if (i == 0) ++res;
                if (j+1 == s.size()) ++res;
                i=j;
            }


        }

        cout << res << endl;
    }
}