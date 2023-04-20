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

int main() {
    fast;
    tests {
        string s;
        cin >> s;

        ll start = 0, end = 0;

        ll ml = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                int j = i;
                while (j+1 < s.size() && s[j+1] == '1') {
                    ++j;
                }

                ml = max(ml, (ll) j-i+1);

                if (i == 0) {
                    start = (j-i+1);
                }
                if (j+1 == s.size()) {
                    end = (j-i+1);
                }
                i = j;
            }
        }

        if (start+end <= s.size()) {
            ml = max(ml, start+end);
        }

        if (ml == s.size()) {
            cout << ml*ml << endl;
        }
        else {
            ll side = (ml+1)/2;
            ll otherside = (ml+2)/2;
            cout << side*otherside << endl;
        }



    }
}