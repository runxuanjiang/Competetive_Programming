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
        ll a, b, c;
        cin >> a >> b >> c;

        ll a_buttons = a + (c+1)/2;
        ll b_buttons = b + c/2;

        if (a_buttons > b_buttons) {
            cout << "First" << endl;
        }
        else {
            cout << "Second" << endl;
        }
    }

}