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
    tests{
        ll n;
        cin >> n;
        map<ll, ll> exp;
        for (int i = 0; i < n; ++i) {
            ll experience;
            cin >> experience;
            if (exp.find(experience) == exp.end()) {
                exp[experience] = 1;
            }
            else ++ exp[experience];
        }

        ll res = 0;
        ll rem = 0;

        for (auto &group : exp) {
            ll tempres = group.second / group.first;
            res += tempres;
            group.second -= (tempres * group.first);
        }

        for (auto group : exp) {
            res += ((group.second + rem) / group.first);
            rem = (group.second + rem) % group.first;
        }



        cout << res << endl;
    }
}