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

int main() {
    fast;
    tests {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> res, dupes;
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); ++i) {
            if (i > 0 && a[i] == a[i-1]) {
                dupes.push_back(a[i]);
            }
            else {
                res.push_back(a[i]);
            }
        }

        for (auto i : dupes) {
            res.push_back(i);
        }

        for (auto i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
}