//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ll res = 1;

void search(vector<ll> &v, int s, int e, int prev, bool left) {
    int mid = (s+e)/2;
    if (left && v[mid] < prev) ++res;
    else if (!left && v[mid] > prev) ++res;
    
    if (s < mid) {
        search(v, s, mid-1, v[mid], true);
    }
    if (e > mid) {
        search(v, mid+1, e, v[mid], false);
    }

}

int main() {
    ll n, m, a, c, x;
    cin >> n >> m >> a >> c >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        x = (a*x+c) % m;
        v[i] = x;
    }

    int s = 0;
    int e = n-1;
    int mid = (n-1)/2;
    search(v, s, mid-1, v[mid], true);
    search(v, mid+1, e, v[mid], false);
    cout << res;
}