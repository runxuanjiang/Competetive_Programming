//Competition #:
//Problem #: G
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
    int n;
    cin >> n;
    ll res = 0;
    ll m = 4294967295;
    stack<ll> stk;
    for (int i = 0; i < n; ++i) {
        string c;
        cin >> c;
        if (c == "for") {
            ll in;
            cin >> in;
            if (stk.empty()) {
                stk.push(in);
            }
            else {
                stk.push(min(m+1, stk.top() * in));
            }
        }
        else if (c == "add") {
            if (stk.empty()) ++res;
            else {
                res += stk.top();
            }
        }
        else if (c == "end") {
            stk.pop();
        }

        if (res > m) {
            cout << "OVERFLOW!!!" << endl;
            return 0;
        }
    }

    cout << res << endl;
}