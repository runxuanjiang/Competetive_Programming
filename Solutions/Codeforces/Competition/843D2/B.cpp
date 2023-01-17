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

        unordered_map<ll, ll> count;
        for (auto i : nums) {
            for (auto j : i) {
                if (count.find(j) == count.end()) {
                    count[j] = 0;
                }
                count[j]++;
            }
        }

        bool res = false;
        for (auto i : nums) {
            bool good = true;
            for (auto j : i) {
                if (count[j] == 1) {
                    good = false;
                }
            }

            if (good) {
                res = true;
            }
        }

        if (res) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }



    }
}