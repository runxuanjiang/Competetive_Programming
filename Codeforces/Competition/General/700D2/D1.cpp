//Competition #:
//Problem #: D
//Accepted: NO!

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }


    int res = 1;
    for (int i = 1; i < n; ++i) {
        ++res;
        if (a[i] == a[i-1]) {
            if (i-3 >= 0 && i-4 >= 0 && a[i] == a[i-3] && a[i] == a[i-4]) {
                --res;
            }
            while (i+1 < n && a[i+1] == a[i]) {
                ++i;
            }
        }
        
    }

    cout << res << endl;


}