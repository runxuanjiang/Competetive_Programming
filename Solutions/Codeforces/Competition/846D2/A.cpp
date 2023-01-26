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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> odds, evens;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] % 2 == 0) {
                evens.push_back(i+1);
            }
            else {
                odds.push_back(i+1);
            }
        }

        if (odds.empty()) {
            cout << "NO" << endl;
        }
        else {
            if (odds.size() == 1) {
                cout << "YES" << endl;
                cout << odds[0] << " " << evens[0] << " " << evens[1] << endl;
            }
            else {
                if (odds.size() == 2 && evens.size() == 1) {
                    cout << "NO" << endl;
                }
                else {
                    cout << "YES" << endl;
                    if (evens.size() >= 2) {
                        cout << evens[0] << " " << evens[1] << " " << odds[0] << endl;
                    }
                    else {
                        cout << odds[0] << " " << odds[1] << " " << odds[2] << endl;
                    }
                }
            }
        }
    }
}