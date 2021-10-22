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
        vector<ll> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        vector<pair<ll, ll>> temp(n);
        for (int i = 0; i < n; ++i) {
            temp[i] = {b[i], i};
        }
        sort(temp.begin(), temp.end());

        vector<ll> res(n);
        int c = 0;
        for (int i = 0; i < n; ++i) {
            res[temp[i].second] = c;
            if (c < temp[i].first) {
                ++c;
            }
        }
        for (auto i : res) {
            cout << i << " ";
        }
        cout << endl;

    }
}