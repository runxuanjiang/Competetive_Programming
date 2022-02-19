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
    int m, n;
    cin >> m >> n;
    vector<vector<string>> sat(m, vector<string>(3));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> sat[i][j];
        }
    }

    if (m < 8) {
        cout << "unsatisfactory" << endl;
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        if (sat[i][0] == sat[i][1] || sat[i][0] == sat[i][2] || sat[i][1] == sat[i][2]) {
            cout << "unsatisfactory" << endl;
            return 0;
        }
        for (auto j : sat[i]) {
            if (j[0] == '-') {
                j = j.substr(1);
            }
            if (stoi(j) > n) {
                cout << "unsatisfactory" << endl;
                return 0;
            }
        }
    }
    cout << "satisfactory" << endl;
}