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

vector<ll> possible(ll p, const vector<pair<ll, pair<ll, ll>>> &problems, ll time) {
    ll count = 0;
    vector<ll> res;
    for (auto prob : problems) {
        if (prob.second.first >= p) {
            time -= prob.first;
            if (time < 0) {
                return {};
            }
            count++;
            res.push_back(prob.second.second);
            if (count >= p) {
                return res;
            }
        }
    }
    return {};
}

int main() {
    fast;
    ll n, t;
    cin >> n >> t;
    vector<pair<ll, pair<ll, ll>>> problems;
    for (int i = 0; i < n; ++i) {
        ll a, time;
        cin >> a >> time;
        problems.push_back({time, {a, i}});
    }

    sort(problems.begin(), problems.end());

    ll lo = 0;
    ll hi = n;

    ll res = 0;
    vector<ll> resProbs;

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (mid == 0) {
            res = 0;
            resProbs = {};

            lo = mid+1;
        }
        else {
            vector<ll> tempres = possible(mid, problems, t);
            if (!tempres.empty()) {
                swap(resProbs, tempres);
                res = mid;
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
    }
    cout << res << endl;
    cout << res << endl;
    for (auto i : resProbs) {
        cout << i+1 << " ";
    }
    cout << endl;





}