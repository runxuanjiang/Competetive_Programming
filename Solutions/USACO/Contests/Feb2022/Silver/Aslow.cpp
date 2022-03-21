//Competition #:
//Problem #: A
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int n;

bool check(const vector<int> &pref, int j) {
    
}

void recurse(int i, const vector<vector<int>> &pref, vector<int> &res, vector<int> &sofar) {
    if (i >= 8) {
        return;
    }

    for (int j = 1; j <= n; ++j) {
        if (!find(sofar.begin(), sofar.end(), j) && check(pref[i], j)) {
            sofar.push_back(j);
            recurse(i+1, pref, res, sofar);
            sofar.pop_back();
        }
    }
}

int main() {
    fast;
    cin >> n;
    vector<vector<int>> pref(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> pref[i][j];
        }
    }

    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i]  = i+1;
    }

    vector<int> sofar;

    recurse(0, pref, res, seen);
    for (auto i : res) {
        cout << res << endl;
    }


}