//Competition #:
//Problem #: F
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

void dfs(ll &curr, ll &num, ll idx, const vector<ll> &primes, vector<pair<ll, ll>> &count, ll &c, ll &s, const ll index) {
    curr *= primes[idx];
    ++num;

    if (num % 2) {
        c -= count[curr].first;
        s -= count[curr].second;
    }
    else {
        c += count[curr].first;
        s += count[curr].second;
    }


    count[curr].first++;
    count[curr].second += index;


    for (int j = idx+1; j < primes.size(); ++j) {
        dfs(curr, num, j, primes, count, c, s, index);
    }

    curr /= primes[idx];
    --num;
}

vector<ll> getPrimes(ll num, const vector<ll> &primes, const vector<bool> &sieve) {
    vector<ll> cprimes;
    for (auto p : primes) {
        if (num == 1) {
            break;
        }
        if (sieve[num]) {
            cprimes.push_back(num);
            break;
        }
        if (num % p == 0) {
            cprimes.push_back(p);
            while (num % p == 0) {
                num /= p;
            }
        }
    }
    return cprimes;
}

int main() {
    fast;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());


    vector<pair<ll, ll>> count(300001, {0, 0});

    vector<bool> sieve(300001, 1);
    sieve[1] = 0;
    vector<ll> primes;
    for (ll i = 2; i <= 300000; ++i) {
        if (sieve[i]) {
            primes.push_back(i);
            for (ll j = 2; j*i <= 300000; ++j) {
                sieve[i*j] = 0;
            }
        }
    }

    ll res = 0;

    for (int i = 0; i < n; ++i) {
        vector<ll> cprimes = getPrimes(a[i], primes, sieve);


        // cerr << "currently on " << a[i] << endl;
        // for (auto p : cprimes) {
        //     cerr << p << " ";
        // }
        // cerr << endl;

        ll c = count[1].first;
        ll s = count[1].second;
        count[1].first++;
        count[1].second += i;
        ll curr = 1;
        ll num = 0;
        for (ll j = 0; j < cprimes.size(); ++j) {
            dfs(curr, num, j, cprimes, count, c, s, i);
        }


        res += (c * i - s - c);
    }

    cout << res << endl;


}