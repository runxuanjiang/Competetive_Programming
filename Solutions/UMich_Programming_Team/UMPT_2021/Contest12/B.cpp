//Competition #:
//Problem #: B
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
    int t;
    cin >> t;

    vector<ll> sieve(1000008, 0);
    for (ll i = 1; i <= 1000007; ++i) {
        ll mult = 2;
        while (mult*i < sieve.size()) {
            sieve[mult*i] += i;
            ++mult;
        }
    }


    for (int i = 0; i < t; ++i) {
        int num;
        cin >> num;
        if (sieve[num] < num) {
            cout << "deficient" << endl;
        }
        else if (sieve[num] > num) {
            cout << "abundant" << endl;
        }
        else {
            cout << "perfect" << endl;
        }
    }


}