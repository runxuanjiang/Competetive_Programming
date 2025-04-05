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
        ll n;
        cin >> n;
        vector<ll> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        vector<ll> element_to_index(n);
        for (int i = 0; i < n; ++i) {
            element_to_index[p[i]] = i;
        }

        vector<bool> fixed(n, false);

        ll res = 0;
        for (int i = 0; i < n; ++i) {
            ll query;
            cin >> query;
            --query;

            // cerr << "query: " << query << endl;


            if (!fixed[query]) {
                ++res;
                ll next_index = element_to_index[query];
                fixed[query] = true;
                while (next_index != query && !fixed[next_index]) {
                    swap(query, next_index);
                    ++res;
                    fixed[query] = true;
                    next_index = element_to_index[query];
                }
            }
            cout << res << " ";

        }

        cout << endl;

    }
}