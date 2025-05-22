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


ll find_max(ll max1, ll max2) {
    if (max2 - max1 == 1) {
        ll result;
        cout << "? " << max1 << " " << max2 << endl;
        cin >> result;
        return (result == 1) ? max1 : max2;
    } else {
        ll result1, result2;
        cout << "? " << max1 << " " << max2-1 << endl;
        cin >> result1;
        cout << "? " << max1 << " " << max2 << endl;
        cin >> result2;

        return (result2 == result1) ? max2 : max1;
    }
}


ll divide_and_conquer(ll l, ll r) {
    if (l == r) {
        return l;
    }
    if (r-l == 1) {
        ll result;
        cout << "? " << l << " " << r << endl;
        cin >> result;
        return (result == 1) ? l : r;
    }

    ll mid = (l+r)/2;
    ll left = divide_and_conquer(l, mid);
    ll right = divide_and_conquer(mid+1, r);
    return find_max(left, right);

}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;

        ll result = divide_and_conquer(1, n);
        cout << "! " << result << endl;


    }
}