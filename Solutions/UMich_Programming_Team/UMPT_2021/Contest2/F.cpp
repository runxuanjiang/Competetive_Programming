//Competition #:
//Problem #: F
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

    vector<int> lb(n), ub(n);

    stack<ll> nums;
    for (int i = 0; i < n; ++i) {
        while (!nums.empty() && a[nums.top()] >= a[i]) {
            nums.pop();
        }

        if (nums.empty()) {
            lb[i] = 0;
        }
        else {
            lb[i] = nums.top() + 1;
        }

        nums.push(i);
    }

    nums = {};
    for (int i = n-1; i >= 0; --i) {
        while (!nums.empty() && a[nums.top()] >= a[i]) {
            nums.pop();
        }

        if (nums.empty()) {
            ub[i] = n-1;
        }
        else {
            ub[i] = nums.top() - 1;
        }

        nums.push(i);
    }

    multiset<ll> rem;
    vector<pair<ll, ll>> ranges;
    for (int i = 0; i < n; ++i) {
        ranges.push_back({ub[i] - lb[i] + 1, a[i]});
        rem.insert(a[i]);
    }

    sort(ranges.begin(), ranges.end());

    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        while (ranges[idx].first < i) {
            rem.erase(rem.find(ranges[idx].second));
            ++idx;
        }

        cout << *(--rem.end()) << " ";
    }
    cout << endl;

}