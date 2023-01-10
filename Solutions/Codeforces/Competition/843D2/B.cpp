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

        vector<vector<ll>> nums(n);
        for (int i = 0; i < n; ++i) {
            ll k;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                ll num;
                cin >> num;
                nums[i].push_back(num);
            }
        }


        ll res = false;
        unordered_set<ll> seen;
        for (auto i : nums) {
            bool good = true;
            for (auto j : i) {
                if (seen.find(j) == seen.end()) {
                    good = false;
                    seen.insert(j);
                }
            }

            if (good) {
                res = true;
            }
        }
        seen = {};
        vector<vector<ll>> rnums(nums.rbegin(), nums.rend());
        for (auto i : rnums) {
            bool good = true;
            for (auto j : i) {
                if (seen.find(j) == seen.end()) {
                    good = false;
                    seen.insert(j);
                }
            }

            if (good) {
                res = true;
            }
        }

        if (res) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }

    }
}