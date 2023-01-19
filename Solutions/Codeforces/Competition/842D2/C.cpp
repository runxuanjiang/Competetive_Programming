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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> sorted(a.begin(), a.end());
        sort(sorted.begin(), sorted.end());

        set<ll> rem1, rem2;
        vector<ll> p, q;

        for (int i = 1; i <= n; ++i) {
            rem1.insert(i);
            rem2.insert(i);
        }

        bool good = true;
        for (auto i : sorted) {
            if (rem1.find(i) != rem1.end() && *rem2.begin() <= i) {
                p.push_back(i);
                q.push_back(*rem2.begin());
                rem1.erase(rem1.find(i));
                rem2.erase(rem2.begin());
            }
            else if (rem2.find(i) != rem2.end() && *rem1.begin() <= i) {
                p.push_back(*rem1.begin());
                q.push_back(i);
                rem1.erase(rem1.begin());
                rem2.erase(rem2.find(i));
            }
            else {
                good = false;
                break;
            }
        }

        if (good) {
            cout << "YES" << endl;
            unordered_map<ll, vector<pair<ll, ll>>> um;
            for (int i = 0; i < sorted.size(); ++i) {
                um[sorted[i]].push_back({p[i], q[i]});
            }

            p = {};
            q = {};
            for (auto i : a) {
                p.push_back(um[i].back().first);
                q.push_back(um[i].back().second);
                um[i].pop_back();
            }

            for (auto i : p) {
                cout << i << " ";
            }
            cout << endl;
            for (auto i : q) {
                cout << i << " ";
            }
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }




    }
}