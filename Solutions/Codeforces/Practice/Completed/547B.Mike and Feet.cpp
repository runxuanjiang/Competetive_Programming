//Competition #: Codeforces Round 305 Div 1
//Problem #: B
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<ll> lbound(n), rbound(n);
    vector<ll> mstack;
    for (int i = 0; i < n; ++i) {
        while (!mstack.empty() && v[mstack.back()] > v[i]) {
            lbound[mstack.back()] = i - mstack.back();
            mstack.pop_back();
        }
        mstack.push_back(i);
    }

    for (auto i : mstack) {
        lbound[i] = n - i;
    }

    mstack = {};
    for (int i = n-1; i >= 0; --i) {
        while (!mstack.empty() && v[mstack.back()] > v[i]) {
            rbound[mstack.back()] = mstack.back() - i;
            mstack.pop_back();
        }

        mstack.push_back(i);
    }

    for (auto i : mstack) {
        rbound[i] = i+1;
    }

    vector<pair<ll, ll>> ranges;
    for (int i = 0; i < n; ++i) {
        ranges.push_back({v[i], lbound[i] + rbound[i] - 1});
    }

    sort(ranges.begin(), ranges.end());
    int curr = ranges.size() - 1;
    for (int i = 0; i < n; ++i) {
        while (ranges[curr].second < i+1) {
            --curr;
        }
        cout << ranges[curr].first << " ";
    }
    cout << endl;





}