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
        ll n, k;
        cin >> n >> k;

        ll res = 0;
        for (int i = 0; i <= n; ++i) {
            ll nums = 2;
            ll high = n, low = i;
            while (nums < k && (high-low <= low)) {
                ll next_low = high-low;
                high = low;
                low = next_low;
                ++nums;
            }

            if (nums == k) {
                ++res;
            }
        }

        cout << res << endl;


    }
}