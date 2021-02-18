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

    int l = 1, r=n;
    int m = find(l, r);

    while (r-l > 1) {
        int mid = l + (r-l)/2;
        if (m < mid) {
            if (find(l, mid) == m) {
                r = mid;
            }
            else {
                l = mid;
                m = find(l, r);
            }
        }
        else {
            if (find(mid, r) == m) {
                l = mid;
            }
            else {
                r = mid;
                m = find(l, r);
            }
        }
    }

    if (l == r) {
        cout << "! " << l << endl;
    }
    else {
        cout << "? " << l << " " << r << endl;
        int m;
        cin >> m;
        cout << "! " << ((m == l) ? r : l) << endl;
    }
}