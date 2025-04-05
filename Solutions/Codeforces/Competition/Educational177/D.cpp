//Competition #:
//Problem #: D
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 998244353;
const int MODINV2 = (998244353 + 1) / 2;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

long long extendedEuclidean(long long a, long long m, long long &x, long long &y) {
    if (m > a) {
        return extendedEuclidean(m, a, y, x);
    }

    if (!m) {
        x = 1;
        y = 0;
        return a;
    }


    long long mult = a/m;
    long long prevx, prevy;
    long long res = extendedEuclidean(m, a-(m*mult), prevx, prevy);
    x = prevy;
    y = prevx - prevy * mult;
    return res;
}

long long modularInverse(long long num, long long mod) {
    long long x, _;
    long long g = extendedEuclidean(num, mod, x, _);
    return ((x % mod) + mod ) % mod;

}

const int MAX_N = 500001;
vector<ll> factorial;
void precomputeFactorials() {
    factorial.resize(MAX_N);
    factorial[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
}

int main() {
    fast;
    precomputeFactorials();

    tests {
        vector<ll> c(26);
        for (int i = 0; i < 26; ++i) {
            cin >> c[i];
        }

        ll sum = 0;
        for (const auto i : c) {
            sum += i;
        }


        if (sum == 1) {
            cout << 1 << endl;
        }
        else {
            ll target = sum/2;
            ll target_factorial = factorial[target];
            ll other_target_factorial = factorial[sum - target];
            ll arrangements = (target_factorial * other_target_factorial) % MOD;
            for (int i = 0; i < 26; ++i) {
                if (c[i] > 0) {
                    arrangements = (arrangements * modularInverse(factorial[c[i]], MOD)) % MOD;
                }
                
            }

            vector<ll> dp(target+1, 0);
            dp[0] = 1;
            for (int i = 0; i < 26; ++i) {
                for (int j = target; j >= 0; --j) {
                    if (c[i] > 0 && c[i] + j <= target) {
                        dp[c[i] + j] += dp[j];
                    }
                }
            }


            cout << (dp[target] * arrangements) % MOD << endl;
        }

    }
}