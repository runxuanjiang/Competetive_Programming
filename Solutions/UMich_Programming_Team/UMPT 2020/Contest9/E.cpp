//Competition #:
//Problem #: E
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

    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    ll cost = 0;

    for (int i = 1; i < a.length(); ++i) {
        if (a[i] != b[i] && a[i-1] != b[i-1] && a[i] != a[i-1]) {
            swap(a[i], a[i-1]);
            cost += 1;
        }
    }

    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) cost += 1;
    }

    cout << cost << '\n';
}