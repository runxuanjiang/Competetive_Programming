//Competition #: Educational round 96 (1430C)
//Problem #: C
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
        ll n;
        cin >> n;

        if (n == 1) {
            cout << 1 << endl;
        }
        else if (n == 2) {
            cout << 2 << endl;
            cout << 2 << " " << 1 << endl;
        }
        else if (n==3) {
            cout << 2 << endl;
            cout << 3 << " " << 2 << endl;
            cout << 3 << " " << 1 << endl;
        }
        else {
            cout << 2 << endl;
            cout << n << " " << n-2 << endl;
            cout << n-1 << " " << n-1 << endl;
            n-=1;
            while (n-2 > 0) {
                cout << n-2 << " " << n << endl;
                --n;
            }
        }
    }
}