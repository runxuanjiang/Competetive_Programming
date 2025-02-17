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

ll findLargestBit(ll x) {
    for (int i = 31; i >= 0; --i) {
        if (x & (1 << i)) {
            return i;
        }
    }
    return -1;
}

ll traverse(ll x, ll i, const vector<vector<ll>>& latestIndexWithLargerBit, const vector<ll>& suffixXor, const vector<ll>& w) {
    // cerr << "traversing with x = " << x << " i = " << i << endl;
    if (i < 0) {
        return 0;
    }
    ll largestBit = findLargestBit(x);
    ll index = latestIndexWithLargerBit[i][largestBit];
    if (index == -1) {
        return 0;
    }
    // cerr << "index = " << index << endl;

    // xor x with all elements from index+1 to i (inclusive)
    x ^= suffixXor[index+1];
    x ^= suffixXor[i+1];

    if (w[index] > x) {
        return index+1;
    }
    
    x ^= w[index];
    if (x == 0) {
        return index;
    }
    return traverse(x, index-1, latestIndexWithLargerBit, suffixXor, w);
}

int main() {
    fast;
    tests {
        ll n, q;
        cin >> n >> q;
        vector<ll> w(n);
        for (int i = 0; i < n; ++i) {
            cin >> w[i];
        }
        vector<vector<ll>> latestIndexWithLargerBit(n, vector<ll>(32, -1));
        for (ll i = 0; i < n; ++i) {
            for (int j = 0; j < 32; ++j) {
                if (i > 0) {
                    latestIndexWithLargerBit[i][j] = latestIndexWithLargerBit[i-1][j];
                }
                if (findLargestBit(w[i]) >= j) {
                    latestIndexWithLargerBit[i][j] = i;
                }
            }
        }

        // for (auto i : latestIndexWithLargerBit) {
        //     for (auto j : i) {
        //         cerr << j << " ";
        //     }
        //     cerr << endl;
        // }
        // cerr << endl;

        vector<ll> suffixXor(n+1, 0);
        for (ll i = n-1; i >= 0; --i) {
            suffixXor[i] = suffixXor[i+1] ^ w[i];
        }

        // for (auto i : suffixXor) {
        //     cerr << i << " ";
        // }
        // cerr << endl;

        for (int i = 0; i < q; ++i) {
            ll x;
            cin >> x;
            cout << n - traverse(x, n-1, latestIndexWithLargerBit, suffixXor, w) << " ";
        }
        cout << endl;
    }
}