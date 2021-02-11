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

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cout << (n-1) / 2 << endl;

    int r = v.size() - 1;
    int l = 0;
    while (r > l) {
        cout << v[r] << " ";
        cout << v[l] << " ";
        --r;
        ++l;
    }
    if (r == l) {
        cout << v[r];
    }

    
}