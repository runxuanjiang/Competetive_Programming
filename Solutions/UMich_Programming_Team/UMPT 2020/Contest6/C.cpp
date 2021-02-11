//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    ll n;
    cin >> n;
    vector<vector<string>> names(n, vector<string>(2));
    for (int i = 0; i < n; ++i) {
        cin >> names[i][0] >> names[i][1];
    }
    vector<ll> order(n);
    for (int i = 0; i < n; ++i) {
        cin >> order[i];
        --order[i];
    }

    string name = min(names[order[0]][0], names[order[0]][1]);
    for (int i = 1; i < n; ++i) {
        if (min(names[order[i]][0], names[order[i]][1]) >= name) {
            name = min(names[order[i]][0], names[order[i]][1]);
        }
        else if (max(names[order[i]][0], names[order[i]][1]) >= name) {
            name = max(names[order[i]][0], names[order[i]][1]);
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}