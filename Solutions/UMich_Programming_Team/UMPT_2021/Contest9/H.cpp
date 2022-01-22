//Competition #:
//Problem #: H
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

bool recurse(int n, string &s, const int &p) {
    if (n < 0) {
        return false;
    }
    s[n]++;
    bool done = false;
    while (!done) {
        while ((s[n] - 'a') < p && ((n > 1 && s[n] == s[n-2]) || (n > 0 && s[n] == s[n-1]))) {
            s[n]++;
        }
        if (s[n] - 'a' >= p) {
            s[n] = 'a';
            bool done = recurse(n-1, s, p);
            if (!done) {
                return false;
            }
        }
        else {
            break;
        }
    }
    return true;
}

int main() {
    fast;
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    bool done = recurse(s.size() - 1, s, p);
    if (done) {
        cout << s << endl;
    }
    else {
        cout << "NO" << endl;
    }



}