//Competition #:
//Problem #: H
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
    string s;
    cin >> s;

    n *= 2;

    cout << s << endl;

    vector<int> a, b, c;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            a.push_back(i);
        }
        else if (s[i] == 'c') {
            c.push_back(i);
        }
        else {
            b.push_back(i);
        }
    }

    int ba = 0, bc = 0;

    cout << a.size() << " " << c.size() << endl;

    if (a.size() > c.size()) {
        ba += ((int) a.size() - (int) c.size());
    }
    else if (a.size() < c.size()) {
        bc += ((int) c.size() - (int) a.size());
    }

    cout << ba << " " << bc << endl;
    if (((int) b.size() - ba - bc) % 2) {
        cout << "NO" << endl;
        return 0;
    }

    int plus =  (((int) b.size() - ba - bc) / 2);
    bc += plus;
    ba += plus;

    set<int> cavail = set<int>(c.rbegin(), c.rend());
    set<int> aavail = set<int> (b.begin(), b.end());
    vector<pair<int, int>> res;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'b') {
            auto it = cavail.lower_bound(i);
            if (it == cavail.end()) {
                cout << "NO" << endl;
                return 0;
            }
            else {
                res.push_back({i, *it});
                cavail.erase(it);
            }
            --bc;
        }
        if (!bc) {
            break;
        }
    }
    for (int i = n-1; i >= 0; --i) {
        if (s[i] == 'b') {
            auto it = aavail.lower_bound(i);
            if (it == aavail.begin()) {
                cout << "NO" << endl;
                return 0;
            }
            else {
                --it;
                res.push_back({*it, i});
                aavail.erase(it);
            }
            --ba;
        }
        if (!ba) {
            break;
        }
    }

    for (auto i : aavail) {
        auto it = cavail.upper_bound(i);
        if (it == cavail.end()) {
            cout << "NO" << endl;
            return 0;
        }
        else {
            res.push_back({i, *it});
            cavail.erase(it);
        }
    }

    cout << "YES" << endl;
    for (auto i : res) {
        cout << i.first << " " << i.second << endl;
    }









    
}