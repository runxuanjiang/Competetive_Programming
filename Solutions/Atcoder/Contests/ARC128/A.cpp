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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> res(n, 0);
    bool up = true;
    int curr = 0;
    for (int i = 1; i < n; ++i) {
        if (up) {
            if (a[i] >= a[i-1]) {
                curr = i;
            }
            else {
                res[curr] = 1;
                up = false;
                curr = i;
            }
        }

        else {
            if (a[i] <= a[i-1]) {
                curr = i;
            }
            else {
                res[curr] = 1;
                up = true;
                curr = i;
            }
        }
    }

    if (!up) {
        res[curr] = 1;
    }

    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
}