//Competition #:
//Problem #: C
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
    ull n;
    cin >> n;

    ull res = 1;
    ull tot = 1;

    vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (auto i : primes) {
        if (res * i > n) {
            break;
        }
        tot *= (i-1);
        res *= i;
    }

    ull num = tot / gcd(res, tot);
    ull den = res / gcd(res, tot);
    cout << den - num << "/" << den << endl;


    
}