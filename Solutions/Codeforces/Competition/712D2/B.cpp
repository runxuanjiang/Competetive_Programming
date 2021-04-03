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
        int n;
        string a, b;
        cin >> n;
        cin >> a >> b;
        vector<int> flips;

        bool impossible = false;
        bool flip = false;

        int zero = 0, one = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] == '0') ++zero;
            else if (a[i] == '1') ++one;
            if (zero == one) flips.push_back(i);
        }

        for (int i = a.length() - 1; i >= 0; --i) {
            while (!flips.empty() && flips.back() > i) {
                flips.pop_back();
            }
            if ((!flip && a[i] != b[i]) || (flip && a[i] == b[i])) {
                if (flips.empty() || flips.back() != i) {
                    impossible = true;
                    break;
                }
                else {
                    flip = !flip;
                    flips.pop_back();
                }
            }
        }

        if (impossible) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}