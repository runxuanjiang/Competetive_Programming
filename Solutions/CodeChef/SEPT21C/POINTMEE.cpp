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

int main() {
    fast;
    tests {
        int n;
        cin >> n;
        vector<ll> x(n), y(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> y[i];
        }

        ll res = 2*n;
        set<pair<ll, ll>> lines;
        for (int i = 0; i < n; ++i) {
            lines.insert({1, x[i]});
            lines.insert({2, y[i]});
            lines.insert({3, y[i] - x[i]});
            lines.insert({4, y[i] + x[i]});
        }

        vector<pair<ld, ld>> intersections;
        for (auto i = lines.begin(); i != lines.end(); ++i) {
            for (auto j = next(i); j != lines.end(); ++j) {
                if (i->first == j->first) {
                    continue;
                }
                pair<ll, ll> lhs = *i, rhs = *j;
                if (lhs.first > rhs.first) {
                    swap(lhs, rhs);
                }

                ld currX, currY;
                if (lhs.first == 1) {
                    currX = lhs.second;
                    if (rhs.first == 2) {
                        currY = rhs.second;
                    }
                    else if (rhs.first == 3) {
                        currY = rhs.second + currX;
                    }
                    else if (rhs.first == 4) {
                        currY = rhs.second - currX;
                    }
                }
                else if (lhs.first == 2) {
                    currY = lhs.second;
                    if (rhs.first == 3) {
                        currX = currY - rhs.second;
                    }
                    else if (rhs.first == 4) {
                        currX = rhs.second - currY;
                    }
                }
                else if (lhs.first == 3) {
                    if (rhs.first == 4) {
                        currX = (ld) (rhs.second - lhs.second) / 2;
                        currY = (ld) (lhs.second + rhs.second) / 2;
                    }
                }

                intersections.push_back({currX, currY});
            }
        }

        for (auto i : intersections) {
            ll tempres = 0;
            for (int j = 0; j < n; ++j) {
                if (i.first == x[j] && i.second == y[j]) {
                    // do nothing;
                }
                else if (i.first == x[j]) {
                    lines.insert({1, i.first});
                    tempres++;
                }
                else if (i.second == y[j]) {
                    lines.insert({2, i.second});
                    tempres++;
                }
                else if (abs(i.first - x[j]) == abs(i.second - y[j])) {
                    if (i.first - x[j] == i.second - y[j]) {
                        lines.insert({3, i.second - i.first});
                    }
                    else if (i.first - x[j] == y[j] - i.second) {
                        lines.insert({4, i.second + i.first});
                    }
                    tempres++;
                }
                else {
                    tempres += 2;
                }
            }
            res = min(res, tempres);
        }
        cout << res << endl;
    }
}