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
    fast;
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    set<int> mexes;
    for (int i = 0; i < v.size(); ++i) {
        set<int> s;
        for (int j = 1; j <= n+1; ++j) {
            s.insert(j);
        }
        for (int j = i; j < v.size(); ++j) {
            s.erase(v[j]);
            mexes.insert(*s.begin());
        }
    }

    if (*mexes.begin() != 1) {
        cout << 1;
    }
    else {
        auto prev = mexes.begin();
        auto next = mexes.begin();
        ++next;
        for (; next != mexes.end(); ++prev, ++next) {
            if (*next - *prev != 1) {
                cout << *next - 1;
                return 0;
            }
        }
        cout << n+1;
    }


}