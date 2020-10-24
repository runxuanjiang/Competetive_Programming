//Competition #: Educational Round 96 D2
//Problem #: A
//Accepted: Yes

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    tests{
        ll n;
        cin >> n;
        for (ll i = 0; i <= n; i+=3) {
            for (ll j = 0; j <= n-i; j+= 5) {
                if ((n - i - j) % 7 == 0) {
                    cout << i/3 << " " << j/5 << " " << (n-i-j)/7 << endl;
                    goto test;
                }
            }
        }
        cout << -1 << endl;

        test: continue;
    }
}