//Competition #:
//Problem #: C
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

bool check(string op, string a, string b, string c) {
    if (op == "+") {
        return (stoll(a) + stoll(b) == stoll(c));
    }
    else {
        return (stoll(a) * stoll(b) == stoll(c));
    }
}

int main() {
    fast;

    string a, b, c;
    string op;
    cin >> a >> op >> b;
    cin >> c >> c;

    for (int i = 1; i < a.size(); ++i) {
        for (int j = 1; j < b.size(); ++j) {
            if (check(op, b.substr(0,j) + a.substr(i), a.substr(0, i) + b.substr(j), c)) {
                cout << b.substr(0,j) + a.substr(i) << " " << op << " " << a.substr(0, i) + b.substr(j) << " = " << c << endl;
                return 0;
            }
        }

        for (int j = 1; j < c.size(); ++j) {
            if (check(op, c.substr(0, j) + a.substr(i), b, a.substr(0, i) + c.substr(j))) {
                cout << c.substr(0, j) + a.substr(i) << " " << op << " " << b << " = " << a.substr(0, i) + c.substr(j) << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i < b.size(); ++i) {
        for (int j = 1; j < c.size(); ++j) {
            if (check(op, a, c.substr(0, j) + b.substr(i), b.substr(0, i) + c.substr(j))) {
                cout << a << " " << op << " " << c.substr(0, j) + b.substr(i) << " = " << b.substr(0, i) + c.substr(j) << endl;
                return 0;
            }
        }
    }


}