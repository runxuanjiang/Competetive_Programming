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
        vector<ll> a(n);
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        if (n == 1) {
            cout << "YES" << endl;
            continue;
        }

        unordered_map<ll, int> counts;
        for (auto i : a) {
            if (counts.find(i) == counts.end()) {
                counts[i] = 0;
            }
            counts[i]++;
        }

        multiset<ll> cuts = {sum};
        for (int i = 0; i+1 < n; ++i) {
            ll cut = *cuts.begin();
            cuts.erase(cuts.begin());
            ll cut1 = cut/2;
            ll cut2 = (cut+1)/2;

            if (counts.find(cut1) != counts.end()) {
                counts[cut1]--;
                if (counts[cut1] == 0) {
                    counts.erase(cut1);
                }
            }
            else {
                cuts.insert(cut1);
            }

            if (counts.find(cut2) != counts.end()) {
                counts[cut2]--;
                if (counts[cut2] == 0) {
                    counts.erase(cut2);
                }
            }
            else {
                cuts.insert(cut2);
            }
        }

        if (cuts.empty()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}