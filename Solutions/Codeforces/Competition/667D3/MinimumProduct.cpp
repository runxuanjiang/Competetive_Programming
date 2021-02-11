//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;
    while (t--) {

        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        if (b > a) {
            swap(a, b);
            swap(x, y);
        }

        ll a1, b1, a2, b2;

        ll sub1 = min(n, a-x);
        a1 = a - sub1;
        b1 = max(b - (n-sub1), y);

        ll sub2 = min(n, b-y);
        b2 = b -sub2;
        a2 = max(a - (n-sub2), x);

        cout << min(a1*b1, a2*b2) << endl;
    }
}