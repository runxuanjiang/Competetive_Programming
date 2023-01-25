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
    string s;
    cin >> s;

    bool good = true;
    ll left = 0;
    vector<ll> lefts;
    for (auto i : s) {
        if (i == '(') {
            ++left;
        }
        else if (i == ')') {
            --left;
        }
        else {
            lefts.push_back(left);
            --left;
        }

        if (left < 0) {
            good = false;
        }
    }

    ll right = 0;
    for (int j = s.size() - 1; j >= 0; --j) {
        if (s[j] == ')') {
            ++right;
        }
        else if (s[j] == '(') {
            --right;
        }
        else {
            break;
        }

        if (right < 0) {
            good = false;
        }
    }


    if (right < 0 || left < 0 || !good) {
        cout << -1 << endl;
    }
    else {
        for (int i = 0; i + 1 < lefts.size(); ++i) {
            cout << 1 << endl;
        }

        cout << lefts.back() - right << endl;

    }

}