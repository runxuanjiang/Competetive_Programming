//Competition #:
//Problem #: E
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

    ll n, m;
    cin >> n >> m;

    vector<set<ll>> nobles(n);
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        nobles[a-1].insert(b-1);
        nobles[b-1].insert(a-1);
    }

    set<ll> vuln;

    for (int i = 0; i < n; ++i) {
        if (!nobles[i].empty() && *(nobles[i].begin()) > i) {
            vuln.insert(i);
        }
    }


    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int com;
        cin >> com;
        if (com == 1) {
            ll a, b;
            cin >> a >> b;

            nobles[a-1].insert(b-1);
            nobles[b-1].insert(a-1);
            if (!nobles[a].empty() && *(nobles[a].begin()) > a) {
                vuln.insert(a);
            }
            else {
                vuln.erase(a);
            }
            if (!nobles[b].empty() && *(nobles[b].begin()) > b) {
                vuln.insert(b);
            }
            else {
                vuln.erase(b);
            }

        }
        else if (com == 2) {
            ll a, b;
            cin >> a >> b;
            nobles[a-1].erase(b-1);
            nobles[b-1].erase(a-1);

            if (!nobles[a].empty() && *(nobles[a].begin()) > a) {
                vuln.insert(a);
            }
            else {
                vuln.erase(a);
            }
            if (!nobles[b].empty() && *(nobles[b].begin()) > b) {
                vuln.insert(b);
            }
            else {
                vuln.erase(b);
            }
        }
        else {
            set<ll> vnext;
            while (!vuln.empty()) {
                int rem = *vuln.begin();
                vuln.erase(vuln.begin());

                for (auto fri : nobles[rem]) {
                    nobles[fri].erase(rem);

                    if (!nobles[fri].empty() && *(nobles[fri].begin()) > fri) {
                        vnext.insert(fri);
                    }
                }
                --n;

                if (vuln.empty()) {
                    vuln = vnext;
                    vnext = {};
                }
            }
            cout << n << endl;
        }
    }

}