//Competition #: Beta Round 77 (96A)
//Problem #: A
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    string s;
    cin >> s;

    ll count0 = 0, count1 = 0, m=0;

    if (s[0] == '0') ++count0;
    else ++count1;

    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == '0') {
            if (s[i] == s[i-1]) ++count0;
            else {
                m = max(count1, m);
                count1 = 0;
                count0 = 1;
            }
        }
        else if (s[i] == '1') {
            if (s[i] == s[i-1]) ++count1;
            else {
                m = max(count0, m);
                count0 = 0;
                count1 = 1;
            }
        }

    }

    m = max(count1, m);
    m = max(count0, m);

    if (m >= 7) cout << "YES";
    else cout << "NO";
}