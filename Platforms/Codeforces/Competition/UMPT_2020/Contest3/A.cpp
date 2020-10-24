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
    ll n, s;
    cin >> n >> s;

    vector<bool> a(n);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        a[i] = (temp == 1);
    }
    vector<bool> b(n);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        b[i] = (temp == 1);
    }

    ll bob = 0, alice = s-1;

    if (!a[bob]) {
        cout << "NO";
    }
    else {
        if (a[alice]) {
            cout << "YES";
        }
        else {
            if (!b[alice]) {
                cout << "NO";
            }
            else {
                bool found = false;
                for (int i = alice; i < n; ++i) {
                    if (a[i] && b[i]) {
                        found = true;
                        break;
                    }
                }
                if (found) cout << "YES";
                else cout << "NO";
            }
        }
    }
}