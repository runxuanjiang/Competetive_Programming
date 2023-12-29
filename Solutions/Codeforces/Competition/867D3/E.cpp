//Competition #:
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>
#include <numeric>

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
        string s;
        cin >> s;

        if (n%2) {
            cout << -1 << endl;
        }
        else {
            vector<ll> count(26, 0);
            for (auto i : s) {
                count[i - 'a']++;
            }

            bool bad = false;
            for (auto i : count) {
                if (i > n/2) {
                    bad = true;
                }
            }
            if (bad) {
                cout << -1 << endl;
            }
            else {
                vector<ll> dcount(26, 0);
                for (int i = 0; i*2 < n; ++i) {
                    if (s[i] == s[n-i-1]) {
                        dcount[s[i] - 'a']++;
                    }
                }

                if (dcount.empty()) {
                    cout << 0 << endl;
                    continue;
                }

                sort(dcount.begin(), dcount.end(), greater());
                ll sum = reduce(dcount.begin(), dcount.end());

                cout << max(dcount[0], (sum+1)/2) << endl;


            }
        }
    }
}