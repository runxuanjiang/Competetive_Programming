//Competition #:
//Problem #: C
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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll &i : a) cin >> i;


        unordered_set<ll> nums(a.begin(), a.end());

        for (int i = 0; i <= n; ++i) {
            if (nums.find(i) == nums.end()) {
                a.push_back(i);
                break;
            }
        }

        vector<ll> new_a(n+1);

        for (int i = 0; i <= n; ++i) {
            new_a[(i + k) % (n+1)] = a[i];
        }

        for (int i = 0; i < n; ++i) {
            cout << new_a[i] << " ";
        }
        cout << endl;



    }
}