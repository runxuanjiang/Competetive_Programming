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
        // cerr << "Tests remaining: " << testCount << endl;
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }


        map<ll, vector<ll>> ao;
        for (int i = 0; i < n; ++i) {
            ao[a[i]].push_back(i);
        }

        ll res = 0;

        for (const auto& i : ao) {
            // cerr << "starting loop for " << i.first << endl;
            if (i.first * i.first > 2*n) {
                break;
            }

            unordered_map<ll, ll> counts;
            ll target = i.first * i.first;
            for (auto x : i.second) {
                if (counts.find(target - b[x]) != counts.end()) {
                    res += counts[target - b[x]];
                }
                if (counts.find(b[x]) == counts.end()) {
                    counts[b[x]] = 0;
                }
                counts[b[x]]++;

            }

            // cerr << "res is now: " << res << endl;


            auto iter = ao.find(i.first);
            ++iter;
            while (iter != ao.end() && i.first * iter->first <= 2*n) {
                // cerr << "trying with " << iter->first << endl;
                target = i.first * iter->first;
                for (auto y : iter->second) {
                    if (counts.find(target - b[y]) != counts.end()) {
                        res += counts[target - b[y]];
                    }
                }
                // cerr << "res is now: " << res << endl;
                ++iter;
            }
        }

        cout << res << endl;

         
    }
}