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
        ll res = 0;
        for (int i = 2; i <= s.size(); ++i) {
            if (s.size() % i == 0) {
                string tempres;
                int len = (int) s.size() / i;
                ll rep = stoll(s.substr(0, len));
                for (int j = 0; j < s.size(); j += len) {
                    if (stoll(s.substr(j, len)) < rep) {
                        --rep;
                        break;
                    }
                }
                for (int j = 0; j < i; ++j) {
                    tempres += to_string(rep);
                }
                res = max(res, stoll(tempres));
            }

        }
        res = max(res, stoll(string(s.size() - 1, '9')));
        cout << res << endl;
    }
}