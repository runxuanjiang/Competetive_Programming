//Competition #:
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

struct compare{
    bool operator() (pair<ll, pair<ll, bool>> lhs, pair<ll, pair<ll, bool>> rhs) {
        if (lhs.first > rhs.first) {
            return false;
        }
        else {
            if (lhs.first == rhs.first) {
                if (lhs.second.second && !rhs.second.second) return true;
                else return false;
            }
        }
        return true;
    }
};

int main() {
    fast;
    ll n;
    cin >> n;
    vector<pair<ll, pair<ll, bool>>> v;
    for (int i = 0; i < n; ++i) {
        ll l, r;
        cin >> l >> r;
        v.push_back({l, {i, true}});
        v.push_back({r, {i, false}});
    }

    sort(v.begin(), v.end(), compare());

    unordered_set<ll> us;


    for (auto i : v) {
        if (i.second.second) {
            us.insert(i.second.first);
        }
        else {
            us.erase(i.second.first);
        }
        if (us.size() > 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}