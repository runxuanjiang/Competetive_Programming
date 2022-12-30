//Competition #:
//Problem #:
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
    ll n;
    cin >> n;
    vector<ll> counts(71, 0);

    for (int i = 0; i < n; ++i) {
        ll num;
        cin >> num;
        counts[num]++;
    }
    vector<ll> mask(71, 0);
    vector<bool> sieve(71, 0);
    vector<ll> primes;
    vector<ll> pow2(n);
    pow2[0] = 1;
    for (int i = 1; i < n; ++i) {
        pow2[i] = (2 * pow2[i-1]) % MOD;
    }

    for (int i = 2; i <= 70; ++i) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j = 2; j*i <= 70; ++j) {
                sieve[j*i] = true;
            }
        }
    }

    for (int i = 2; i <= 70; ++i) {
        for (int j = 0; j < primes.size(); ++j) {
            int count = 0;
            int curr = i;
            while (curr % primes[j] == 0) {
                ++count;
                curr /= primes[j];
            }

            if (count % 2) {
                mask[i] |= (1 << j);
            }
        }
    }

    vector<vector<ll>> dp(2, vector<ll>((1 << primes.size()), 0));
    if (counts[1]) {
        dp[0][0] = (pow2[counts[1] - 1] * 2 - 1) % MOD;
    }
    else {
        dp[0][0] = 0;
    }


    for (ll i = 2; i <= 70; ++i) {
        for (int j = 0; j < (1 << primes.size()); ++j) {
            dp[1][j] = 0;
        }
        if (counts[i]) {
            dp[1][0] = (dp[1][0] + pow2[counts[i] - 1] - 1 + MOD) % MOD;
            dp[1][mask[i]] = (dp[1][mask[i]] + pow2[counts[i] - 1]) % MOD;
        }
        for (ll j = 0; j < (1 << primes.size()); ++j) {
            if (counts[i]) {
                dp[1][j] = (dp[1][j] + dp[0][j] * pow2[counts[i] - 1]) % MOD;
                dp[1][j] = (dp[1][j] +  dp[0][mask[i] ^ j] * pow2[counts[i] - 1]) % MOD;
            }
            else {
                dp[1][j] = dp[0][j];
            }

        }

        dp[0] = dp[1];

    }

    cout << dp[0][0] << endl;

    
}