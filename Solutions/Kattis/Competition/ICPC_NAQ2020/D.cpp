//Competition #:
//Problem #: D
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
    int w, p;
    cin >> w >> p;
    vector<int> a(p+2);
    a[0] = 0;
    for (int i = 0; i < p; ++i) {
        cin >> a[i+1];
    }
    a.back() = w;

    set<int> res;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i+1; j < a.size(); ++j) {
            res.insert(a[j]-a[i]);
        }
    }

    for (auto i : res) {
        cout << i << " ";
    }
}