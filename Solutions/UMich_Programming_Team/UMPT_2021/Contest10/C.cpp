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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<int> x, y;
    for (int i = 1; i <= n; ++i) {
        y.insert(i);
    }
    for (auto i : a) {
        x.insert(i);
        while (!x.empty() && *(--x.end()) == *(--y.end())) {
            cout << *(--x.end()) << " ";
            x.erase(--x.end());
            y.erase(--y.end());
        }
        cout << endl;
    }
}