//Competition #:
//Problem #: H
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

    bool done = true;
    int start = -1;
    for (int i = 0; i < n; ++i) {
        if (done) {
            start = a[i];
            done = false;
        }
        else {
            if (a[i] % start == 0) {
                cout << a[i] << endl;
                done = true;
            }
        }
    }
}