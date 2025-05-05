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

bool recurse(ll i, ll positives, unordered_multiset<ll> &counts, unordered_map<ll, vector<ll>> &res) {

    if (i < 0) {
        return true;
    }

    ll hi_count = i + 1 + positives;
    ll lo_count = positives;

    if (counts.find(hi_count) != counts.end()) {
        counts.erase(counts.find(hi_count));
        res[hi_count].push_back(i+1);
        if (recurse(i-1, positives+1, counts, res)) {
            return true;
        }
        counts.insert(hi_count);
        res[hi_count].pop_back();
    }

    if (counts.find(lo_count) != counts.end()) {
        counts.erase(counts.find(lo_count));
        res[lo_count].push_back(-(i+1));
        if (recurse(i-1, positives, counts, res)) {
            return true;
        }
        counts.insert(lo_count);
        res[lo_count].pop_back();
    }

    return false;


}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        unordered_multiset<ll> counts(a.begin(), a.end());
        vector<ll> b(n);
        unordered_map<ll, vector<ll>> res;

        bool good = recurse(n-1, 0, counts, res);
        if (good) {

            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << res[a[i]].back() << " ";
                res[a[i]].pop_back();
            }
            cout << endl;
        }
        else {
            cout << "NO\n";
        }

        


    }
}