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
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<bool> sieve(50, 0);
        vector<ll> primes;
        for (int i = 2; i < 50; ++i) {
            if (!sieve[i]) {
                primes.push_back(i);
                for (int j = 1; j*i < 50; ++j) {
                    sieve[j*i] = true;
                }
            }
        }

        bool res = true;
        unordered_set<ll> seen;
        for (auto i : a) {
            if (seen.find(i) != seen.end()) {
                res = false;
            }
            seen.insert(i);
        }

        for (auto prime : primes) {
            vector<int> count(prime, 0);
            for (auto i : a) {
                count[i % prime]++;
            }

            bool good = false;
            for (auto i : count) {
                if (i < 2) {
                    good = true;
                }
            }

            if (!good) {
                res = false;
            }
        }

        if (res) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}