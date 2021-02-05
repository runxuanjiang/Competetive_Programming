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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(n), c(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> c[i];
        }

        unordered_map<ll, pair<ll, vector<ll>> > paint;
        bool complete = true;

        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                if (paint.find(b[i]) == paint.end() || paint[b[i]].first == 0) {
                    paint[b[i]] = {1, {i+1}};
                }
                else {
                    ++paint[b[i]].first;
                    paint[b[i]].second.push_back(i+1);
                }
            }
            else {
                if (paint.find(b[i]) == paint.end()) {
                    paint[b[i]] = {0, {i+1}};
                }
            }
        }
        bool extra = false;
        vector<ll> painters;

        for (int i = m-1; i >= 0; --i) {
            if (paint.find(c[i]) != paint.end()) {
                extra = true;
                --paint[c[i]].first;
                if (paint[c[i]].first >= 0) {
                    painters.push_back(paint[c[i]].second[paint[c[i]].first]);
                }
                else {
                    painters.push_back(paint[c[i]].second.front());
                }
            }
            else {
                if (!extra) {
                    complete = false;
                    goto done;
                }
                else {
                    painters.push_back(painters.back());
                }
            }
        }
        for (auto i : paint) {
            if (i.second.first > 0) {
                complete = false;
            }
        }

        done: if (complete) {
            cout << "YES\n";
            for (auto i = painters.rbegin(); i != painters.rend(); ++i) {
                cout << *i << " ";
            }
            cout << endl;
        }
        else {
            cout << "NO\n";
        }
    }
}