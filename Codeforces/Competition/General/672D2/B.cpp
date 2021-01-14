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
    tests{
        ll cells;
        cin >> cells;
        ll count = 0;
        ll i = 0;
        ll add = 1;
        ll res = 0;
        while (res <= cells) {
            ++count;
            i += add;
            add *= 2;
            res += (i*(i+1) / 2);
        }
        cout << count-1 << endl;
    }
}