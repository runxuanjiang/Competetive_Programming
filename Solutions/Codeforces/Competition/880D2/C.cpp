//Competition #:
//Problem #: C
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ll pow10(ll exp) {
    ll res = 1;
    for (int i = 0; i < exp; ++i) {
        res *= 10;
    }
    return res;
}

int main() {
    fast;
    tests {
        ll A, B, C, k;
        cin >> A >> B >> C >> k;

        ll ares = 0, bres = 0;

        if (C == max(A, B)) {
            ll mintarget = pow10(C-1);
            ll maxtarget = pow10(C)-1;
            for (ll i = pow10(A-1); i < pow10(A); ++i) {
                ll currentMin = pow10(B-1);
                ll currentMax = min(pow10(B)-1, maxtarget - i);

                if (currentMin <= currentMax) {
                    ll diff = currentMax - currentMin + 1;
                    if (diff >= k) {
                        ares = i;
                        bres = currentMin + k - 1;
                        break;
                    }
                    else {
                        k -= diff;
                    }
                }
            }
        }
        else if (C == max(A, B) + 1) {
            ll mintarget = pow10(C-1);
            ll maxtarget = pow10(C)-1;
            for (ll i = pow10(A-1); i < pow10(A); ++i) {
                ll currentMax = pow10(B)-1;
                ll currentMin = max(pow10(B-1), mintarget - i);

                if (currentMin <= currentMax) {
                    ll diff = currentMax - currentMin + 1;
                    if (diff >= k) {
                        ares = i;
                        bres = currentMin + k - 1;
                        break;
                    }
                    else {
                        k -= diff;
                    }
                }
            }
        }
        else {
            cout << -1 << endl;
            continue;
        }

        if (ares && bres) {
            cout << ares << " + " << bres << " = " << ares + bres << endl;
        }
        else {
            cout << -1 << endl;
        }

    }
}