//Competition #:
//Problem #: D
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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll cycles = 0;
        bool good = false;
        for (int i = 0; i < n; ++i) {
            if (a[i]) {
                ++cycles;
                unordered_set<ll> seen;
                int curr = i;
                while (a[curr]) {
                    if (seen.find(a[curr] + 1) != seen.end() || seen.find(a[curr] - 1) != seen.end()) {
                        good = true;
                    }
                    seen.insert(a[curr]);
                    int temp = curr;
                    curr = a[curr] - 1;
                    a[temp] = 0;
                }
            }

        }

        if (good) {
            cout << (n-cycles) -1 << endl;
        }
        else {
            cout << n-cycles + 1 << endl;
        }


    }
}