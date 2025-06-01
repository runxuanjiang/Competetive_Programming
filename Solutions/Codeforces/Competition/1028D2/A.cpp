//Competition #:
//Problem #: A
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
    tests {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll a_moves = min(b, d);
        ll b_moves = min(a, c);

        if (a_moves <= b_moves) {
            cout << "Gellyfish" << endl;
        }
        else {
            cout << "Flower" << endl;
        }
    }
}