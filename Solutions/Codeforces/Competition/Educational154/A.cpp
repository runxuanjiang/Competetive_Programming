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


bool is_prime(ll x) {
    for (int i = 2; i*i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    fast;
    tests {
        string num_str;
        cin >> num_str;


        ll res = -1;

        for (unsigned i = 0; i <= (1 << 10); ++i) {
            if (popcount(i) >= 2) {
                string curr;
                for (int j = 0; j < 10; ++j) {
                    if (i & (1 << j)) {
                        curr.push_back(num_str[j]);
                    }
                }

                if (is_prime(stoll(curr))) {
                    res = stoll(curr);
                    break;
                }
            }
        }

        cout << res << endl;
    }
}