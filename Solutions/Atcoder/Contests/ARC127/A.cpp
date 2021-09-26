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


long long solve(string n) {
    ll nint = stoll(n);

    int idx = 0;
    while ((idx < (int) n.size()) && n[idx] == '1') {
        ++idx;
    }

    int digits = n.size() - idx;
    ll tsum = 0;
    ll curr = 1;
    for (int i = 0; i < digits; ++i) {
        tsum += curr;
        curr *= 10;
    }

    ll res = 0;
    while (n[0] == '1' && idx >= 0) {
        if (idx + 1 == n.size() && n[idx] != '0') {
            res++;
        }
        else if (n[idx] == '1') {
            res += stoll(n.substr(idx+1)) + 1;
        }
        else if (n[idx] >= '2') {
            res += tsum;
        }

        tsum += curr;
        curr *= 10;
        --idx;
    }



    tsum = 0;
    curr = 1;
    while (curr <= nint) {
        tsum += curr;
        curr *= 10;
    }
    if (n[0] != '1') {
        tsum += curr;
        curr *= 10;
    }



    while (curr > 0) {
        curr /= 10;
        tsum -= curr;
        res += tsum;

    }

    return res;
}


int main() {
    fast;
    string n;
    cin >> n;
    cout << solve(n) << endl;

}