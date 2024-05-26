//Competition #:
//Problem #: D
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

void recurse(int node, int prev, vector<ll> &tot, vector<vector<ll>> &branches, const vector<vector<ll>> &g, const ll n) {
    tot[node] = 1;
    for (auto child : g[node]) {
        if (child != prev) {
            recurse(child, node, tot, branches, g, n);
            branches[node].push_back(tot[child]);
            tot[node] += tot[child];
            branches[child].push_back(n-tot[child]);
        }
    }
}

ll modinverse(ll a) {
    a %= MOD;
    return a <= 1 ? a : MOD - (MOD/a) * modinverse(MOD % a) % MOD;
}

void printres(ll num, ll denom) {
    cout << ((num % MOD) * (modinverse(denom) % MOD) ) % MOD << endl;
}

int main() {
    fast;
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> g(n);
    for (int i = 0; i+1 < n; ++i) {
        ll a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }


    vector<ll> tot(n, 0);
    vector<vector<ll>> branches(n);
    recurse(0, -1, tot, branches, g, n);

    if (n < k) {
        cout << 0 << endl;
    }
    else {
        if (k == 1) {
            cout << 1 << endl;
        }
        else if (k == 2) {
            ll denom = n*(n-1)/2;
            ll num = 0;
            for (const auto &bs : branches) {
                // when current node is one of the k
                num += (n-1);

                // when current node is not one of the k
                ll rem = n-1;
                for (auto b : bs) {
                    rem -= b;
                    num += (rem * b);
                }
            }
            printres(num, denom);
        }
        else if (k == 3) {
            ll denom = n*(n-1)*(n-2)/6;
            ll num = 0;
            for (const auto &bs : branches) {
                ll rem = n-1;
                ll overrem = 0;
                for (auto b : bs) {
                    overrem += (b*(b-1)/2);
                }



                for (auto b : bs) {
                    rem -= b;
                    overrem -= (b*(b-1)/2);
                    // when current node is one of the k
                    num += (rem * b);

                    // when current node is not one of the k
                    ll options = rem * (rem-1)/2 - overrem;
                    num += (b * options);
                }
            }
            printres(num, denom);
        }
    }



    
}