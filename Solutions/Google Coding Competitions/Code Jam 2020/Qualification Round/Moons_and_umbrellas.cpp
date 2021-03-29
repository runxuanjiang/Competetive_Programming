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

// NOTE: did not attempt the "extra credit" portion of the problem

int CASE = 1;

int main() {
    fast;
    tests {
        long long x, y;
        cin >> x >> y;
        string seq;
        cin >> seq;

        int res = 0;

        char prev = '?';
        for (int i = 0; i < seq.length(); ++i) {
            if (seq[i] == '?') {
                continue;
            }
            else if (prev == '?') {
                prev = seq[i];
            }
            else if (seq[i] != prev) {
                prev = seq[i];
                res += ((seq[i] == 'C') ? y : x);
            }
        }

        cout << "Case #" << CASE << ": " << res << endl;
        ++CASE;
    }
}