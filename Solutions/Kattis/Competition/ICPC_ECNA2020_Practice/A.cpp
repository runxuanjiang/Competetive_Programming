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

int sumOfDigits(int a) {
    int res = 0;
    while (a > 0) {
        res += (a % 10);
        a/= 10;
    }
    return res;
}

int main() {
    fast;
    int in;

    while (cin >> in) {
        if (in == 0) {
            return 0;
        }

        int sd = sumOfDigits(in);
        
        for (int i = 11; i <= 100; ++i) {
            if (sumOfDigits(i*in) == sd) {
                cout << i << endl;
                break;
            }
        }
    }
}