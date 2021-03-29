//Competition #:
//Problem #: B
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

struct comp{
    bool operator() (ll lhs, ll rhs) {
        return (lhs > rhs);
    }
};

int main() {
    fast;
    tests {
        ll n, W;
        cin >> n >> W;
        unordered_map<ll, int> um;
        for (int i = 0; i < n; ++i) {
            long long in;
            cin >> in;
            if (um.find(in) == um.end()) {
                um[in] = 1;
            }
            else {
                ++um[in];
            }
        }


        ll height = 0;
        while (!um.empty()) {
            ++height;
            ll width = W;

            for (int i = 29; i >= 0; --i) {
                ll exp = pow(2, i);
                if (um.find(exp) != um.end() && exp <= width) {
                    ll sub = min((long long) um[exp], (long long) (width / exp));
                    width -= sub * exp;
                    um[exp] -= sub;

                    if (um[exp] <= 0) {
                        um.erase(exp);
                    }
                }
            }
        }
        cout << height << endl;


    }
}