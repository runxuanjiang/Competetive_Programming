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

pair<bool, bool> kmp(vector<ll> start, vector<ll> end) {
    pair<bool, bool> res = {false, false};

    for (int i = 0; i + 1 < start.size(); ++i) {
        end.push_back(end[i]);
    }

    vector<ll> loss(start.size(), 0);
    int curr = 0;
    for (int i = 1; i < start.size(); ++i) {
        while (curr && start[i] != start[curr]) {
            curr = loss[curr-1];
        }
        if (start[i] == start[curr]) {
            ++curr;
        }
        loss[i] = curr;
    }

    curr = 0;
    for (int i = 0; i < end.size(); ++i) {
        while (curr && end[i] != start[curr]) {
            curr = loss[curr-1];
        }
        if (end[i] == start[curr]) {
            ++curr;
        }

        if (curr == start.size()) {
            if (i - start.size() + 1) {
                res.second = true;
            }
            else {
                res.first = true;
            }

            curr = loss[curr-1];
        }
    }

    return res;
}

int main() {
    fast;

    int test = 0;
    tests {
        ++test;
        cout << "Case #" << test << ": ";

        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        vector<ll> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        auto rotations = kmp(a, b);

        bool good = true;
        if (!rotations.first && !rotations.second) {
            good = false;
        }

        if (n == 2) {
            if (k % 2 == 0) {
                if (!rotations.first) {
                    good = false;
                }
            }
            else {
                if (!rotations.second) {
                    good = false;
                }
            }
        }
        else {
            if (k == 0) {
                if (!rotations.first) {
                    good = false;
                }
            }
            else if (k == 1) {
                if (!rotations.second) {
                    good = false;
                }
            }
        }

        if (good) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

        

    }
}