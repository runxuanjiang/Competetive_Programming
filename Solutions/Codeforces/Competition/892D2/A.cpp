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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        if (a.front() == a.back()) {
            cout << -1 << endl;
        }
        else {
            vector<ll> b, c;
            for (int i = 0; i < n; ++i) {
                if (a[i] == a.front()) {
                    b.push_back(a[i]);
                } else {
                    c.push_back(a[i]);
                }
            }

            cout << b.size() << " "<< c.size() << endl;
            for (auto x : b) {
                cout << x << " ";
            }
            cout << endl;
            for (auto x : c) {
                cout << x << " ";
            }
            cout << endl;
        }


    }
}