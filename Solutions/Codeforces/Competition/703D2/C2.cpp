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

int find(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int in;
    cin >> in;
    return in;
}

int main() {
    int n;
    cin >> n;

    int m = find(1, n);
    int res = 0;
    if ( !(m == 1) && (m == n || find(1, m) == m)) {
        int l = 1, r = m-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (find(mid, m) == m) {
                res = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        res = r;
    }
    else {
        int l = m+1, r = n;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (find(m, mid) == m) {
                res = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        res = l;
    }
    cout << "! " << res << endl;
}