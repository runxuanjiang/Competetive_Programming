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
    ll n, x, pos;
    cin >> n >> x >> pos;

    ll lower = 0;
    ll higher = 0;

    ll left = 0, right = n;
    while (left < right) {
        ll middle = (left + right) / 2;
        if (middle <= pos) {
            if (middle < pos) {
                ++lower;
            }
            left = middle+1;
        }
        else {
            ++higher;
            right = middle;
        }
    }

    ll numlower = x-1;
    ll numhigher = n-x;

    ll res = 1;
    ll tl = lower, th = higher;
    while (lower--) {
        res = (res * numlower) % MOD;
        --numlower;
    }
    while (higher--) {
        res = (res * numhigher) % MOD;
        --numhigher;
    }


    ll numleft = n - tl - th - 1;
    while (numleft > 0) {
        res = (res * numleft) % MOD;
        numleft-=1;
    }

    cout << res % MOD;
}