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
    fast;
    int n, m;
    cin >> n >> m;
    vector<ll> dorms(n+1);
    dorms[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> dorms[i+1];
        dorms[i+1] += dorms[i];
    }
    dorms.pop_back();
    for (int i = 0; i < m; ++i) {
        ll dest;
        cin >> dest;
        auto iter = upper_bound(dorms.begin(), dorms.end(), dest);
        if (iter == dorms.end()) iter = dorms.begin() + (dorms.size() - 1);
        else {
            --iter;
        }

        cout << (iter - dorms.begin() + 1) << " " << dest - *iter + 1 << endl;

    }





}