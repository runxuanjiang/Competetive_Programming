//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ll n, k, A, B;

ll recurse(ll start, ll end, vector<ll> &avengers) {
    auto lb = lower_bound(avengers.begin(), avengers.end(), start);
    auto ub = lower_bound(avengers.begin(), avengers.end(), end);
    ll startiter = (lb == avengers.end()) ? avengers.size() : lb - avengers.begin();
    ll enditer = (ub == avengers.end()) ? avengers.size() : ub - avengers.begin();
    ll num = enditer - startiter;
    if (num == 0) return A;

    if (end - start == 1) {
        return B*num;
    }

    ll small1 = (end - start) * B * num;
    ll half = (end-start)/2;
    ll small2 = recurse(start, start+half, avengers) + recurse(start+half, end, avengers);
    return min(small1, small2);
}

int main() {
    fast;
    cin >> n >> k >> A >> B;
    vector<ll> avengers(k);
    for (int i = 0; i < k; ++i) {
        cin >> avengers[i];
        --avengers[i];
    }
    sort(avengers.begin(), avengers.end());
    cout << recurse(0, pow(2, n), avengers);
}