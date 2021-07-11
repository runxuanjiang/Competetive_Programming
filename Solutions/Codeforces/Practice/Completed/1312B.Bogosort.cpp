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
        int n;
        cin >> n;
        vector<ll> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end(), greater<ll>());

        for (auto i : nums) {
            cout << i << " ";
        }
        cout << endl;
    }
}