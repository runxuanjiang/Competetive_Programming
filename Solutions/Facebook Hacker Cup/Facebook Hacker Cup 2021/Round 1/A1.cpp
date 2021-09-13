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

int testnum = 0;

int main() {
    fast;
    tests {
        ++testnum;
        cout << "Case #" << testnum << ": ";
        ll n;
        string w;
        cin >> n;
        cin >> w;

        char curr = '.';
        ll switches = 0;
        for (auto i : w) {
            if (i != 'F' && i != curr) {
                if (curr == '.') {
                    curr = i;
                }
                else {
                    ++switches;
                    curr = i;
                }
            }
        }

        cout << switches << endl;
    }
}