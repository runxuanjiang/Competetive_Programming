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

int main() {
    fast;
    tests {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> sorted(a.begin(), a.end());
        sort(sorted.begin(), sorted.end());

        ll res = 0;
        ll rem = m;
        for (auto i : sorted) {
            if (rem >= i) {
                rem -= i;
                ++res;
            }
            else {
                break;
            }
        }

        if (res == n) {
            cout << 1 << endl;
        }
        else {
            bool good = true;
            if (m < a[res]) {
                good = false;
            }
            else {
                m -= a[res];
                sorted.erase(find(sorted.begin(), sorted.end(), a[res]));
                ll tempres = 1;
                for (auto i : sorted) {
                    if (m >= i) {
                        m -= i;
                        ++tempres;
                    }
                    else {
                        break;
                    }
                }
                if (tempres < res) {
                    good = false;
                }
            }

            if (good) {
                ++res;
            }

            cout << n+1-res << endl;
        }
    }
}