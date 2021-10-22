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
    tests {
        vector<int> a(5);
        for (int i = 0; i < 5; ++i) {
            cin >> a[i];
        }
        int eng = 0, ind = 0;
        for (auto i : a) {
            if (i == 1) {
                ++ind;
            }
            else if (i == 2) {
                ++eng;
            }
        }

        if (eng > ind) {
            cout << "ENGLAND\n";
        }
        else if (ind > eng) {
            cout << "INDIA\n";
        }
        else {
            cout << "DRAW\n";
        }
    }
}