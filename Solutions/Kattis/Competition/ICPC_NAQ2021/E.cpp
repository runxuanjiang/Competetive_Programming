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
    string s;
    cin >> s;
    int left = 0, right = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            left = i;
            right = s.size() - i - 2;
            break;
        }
    }

    if (left == right) {
        cout << "correct" << endl;
    }
    else {
        cout << "fix" << endl;
    }
}