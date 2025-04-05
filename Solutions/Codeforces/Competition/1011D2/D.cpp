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

int main() {
    fast;
    tests {
        ll n, k;
        cin >> n >> k;
        vector<ll> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }

        for (int i = 0; i < k; ++i) {
            d.pop_back();
        }


        vector<ll> d_reverse(d.rbegin(), d.rend());

        ll res = 0;
        multiset<ll> current_batch;
        ll current_batch_sum = 0;

        for (int i = 0; i < d_reverse.size(); ++i) {
            if (i % (k+1) == 0) {
                current_batch.insert(d_reverse[i]);
                current_batch_sum += d_reverse[i];
                res = max(res, current_batch_sum);
            }
            else {
                ll min_element = *current_batch.begin();
                if (d_reverse[i] > min_element) {
                    current_batch.erase(current_batch.find(min_element));
                    current_batch.insert(d_reverse[i]);
                    current_batch_sum -= min_element;
                    current_batch_sum += d_reverse[i];
                    res = max(res, current_batch_sum);
                }
            }
        }

        cout << res << endl;




    }
}