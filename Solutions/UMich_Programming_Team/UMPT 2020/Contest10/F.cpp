//Competition #:
//Problem #: F
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
    string s;
    cin >> s;
    int m;
    cin >> m;
    for (int i = 0 ; i < m; ++i) {
        ll l, r, k;
        cin >> l >> r >> k;
        --l; --r;
        k %= (r-l+1);

        string news = s.substr(l, r-l+1);
        for (int i = 0; i < k; ++i) {
            news = news.back() + news.substr(0, news.length() - 1);
        }

        s.replace(l, r-l+1, news);
    }

    cout << s;
}