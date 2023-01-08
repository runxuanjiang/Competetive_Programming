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

int main() {
    fast;
    tests {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        if (a.front() == a.back()) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            cout << a[0] << " ";
            for (int i = n-1; i >= 1; --i) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

}