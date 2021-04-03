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

int n;

void incr(pair<int, int> &p) {
    if (p.second + 2 <= n) {
        p.second += 2;
    }
    else {
        p.first += 1;
        p.second = (p.second % 2 == 0) ? 1 : 2;
    }
}

int main() {
    fast;
    cin >> n;
    pair<int, int> odd = {1, 1};
    pair<int, int> even = {1, 2};
    for (int i = 0; i < n*n; ++i) {
        int a;
        cin >> a;

        if (a == 1) {
            if (even.first > n) {
                cout << 3 << " " << odd.first << " " << odd.second << endl;
                incr(odd);
            }
            else {
                cout << 2 << " " << even.first << " " << even.second << endl;
                incr(even);
            }

        }

        else if (a == 2) {
            if (odd.first > n) {
                cout << 3 << " " << even.first << " " << even.second << endl;
                incr(even);
            }
            else {
                cout << 1 << " " << odd.first << " " << odd.second << endl;
                incr(odd);
            }
        }

        else if (a == 3) {
            if (even.first > n) {
                cout << 1 << " " << odd.first << " " << odd.second << endl;
                incr(odd);
            }
            else {
                cout << 2 << " " << even.first << " " << even.second << endl;
                incr(even);
            }
        }
    }
}