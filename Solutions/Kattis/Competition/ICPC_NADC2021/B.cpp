//Competition #:
//Problem #: B
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

/*
    NOTE: Code is roughly inspired by the following source:
    https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
    https://gist.github.com/YDrall/d782a03430d5002cc3bc
*/

int main() {
    fast;
    string s;
    cin >> s;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string t;
        int maxi;
        cin >> t;
        cin >> maxi;

        if (t.length() + maxi -1 > s.length()) {
            cout << -1 << endl;
            continue;
        }

        vector<int> pattern(t.length(), 0);
        for (int j = 1; j < t.length(); ++j) {
            int k = pattern[j-1];
            while (k > 0 && t[j] != t[k]) {
                k = pattern[k-1];
            }
            if (t[j] == t[k]) ++k;
            pattern[j] = k;
        }

        int count = 0;
        bool found = false;

        for (int j = 0, k = 0; j < s.length(); ++j) {
            while (k > 0 && t[k] != s[j]) {
                k = pattern[k-1];
            }
            if (t[k] == s[j]) ++k;
            if (k == t.length()) {
                ++count;
                if (count == maxi) {
                    found = true;
                    cout << j-k+2 << endl;
                    break;
                }
                k = pattern[k-1];
            }
        }

        if (!found) {
            cout << -1 << endl;
        }

    }
}