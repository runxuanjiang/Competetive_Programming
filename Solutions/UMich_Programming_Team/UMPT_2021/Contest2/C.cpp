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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    multiset<ll> nums;
    int res = 0;
    for (auto i : a) {
        if (!nums.empty() && i > *(nums.begin())) {
            ++res;
            nums.erase(nums.begin());
        }
        nums.insert(i);
    }

    cout << res << endl;
}