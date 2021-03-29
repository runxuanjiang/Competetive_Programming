//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int CASE = 1;

int main() {
    fast;
    tests {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int res = 0;
        for (int i = 0; i < n-1; ++i) {
            int m = a[i];
            int midx = i;
            for (int j = i; j < n; ++j) {
                if (a[j] < m) {
                    m = a[j];
                    midx = j;
                }
            }

            res += (midx - i + 1);
            int l = i, r = midx;
            while (l < r) {
                swap(a[l], a[r]);
                ++l;
                --r;
            }
        }

        cout << "Case #" << CASE << ": " << res << endl;
        ++CASE;
    }
}