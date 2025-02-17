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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        unordered_map<ll, ll> counts;
        for (int i = 0; i < n; ++i) {
            if (counts.find(a[i]) == counts.end()) {
                counts[a[i]] = 0;
            }
            ++counts[a[i]];

        }

        ll resl = 0, resr = 0;
        ll longestSequence = 0;
        ll currentLongestSequence = 0;
        ll cresl = 0, cresr = 0;
        for (int i = 0; i < n; ++i) {
            if (counts[a[i]] == 1) {
                if (!currentLongestSequence) {
                    cresl = i;
                }
                ++currentLongestSequence;
            } else {
                cresr = i-1;
                if (currentLongestSequence > longestSequence) {
                    longestSequence = currentLongestSequence;
                    resl = cresl;
                    resr = cresr; 
                }
                currentLongestSequence = 0;
            }
        }
        if (currentLongestSequence > longestSequence) {
            longestSequence = currentLongestSequence;
            resl = cresl;
            resr = n-1; 
        }

        if (longestSequence == 0) {
            cout << 0 << endl;
        } else {
            cout << resl+1 << " " << resr+1 << endl;
        }



    }
}