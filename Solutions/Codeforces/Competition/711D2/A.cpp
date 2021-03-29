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

int sumOfDigits(long long x) {
    long long sum = 0;
    while (x > 0) {
        sum += (x % 10);
        x /= 10;
    }

    return sum;
}

int main() {
    fast;
    tests {
        long long n;
        cin >> n;
        while (gcd(n, sumOfDigits(n)) == 1) {
            ++n;
        }
        cout << n << endl;
    }
}