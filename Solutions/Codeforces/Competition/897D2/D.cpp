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


bool recurse(int node, int idx, const vector<ll> &b, vector<ll> &seen_index, const ll k) {
    seen_index[node] = idx;
    int next = b[node];
    // cerr << "at node " << node << " idx " << idx << " next " << next << " seen_index " << seen_index[next] << endl;
    bool good;
    if (seen_index[next] == -1) {
        good = true;
    }
    else if (seen_index[next] == 0) {
        good = recurse(next, idx+1, b, seen_index, k);
    }
    else {
        int loop_length = idx-seen_index[next]+1;
        good = (loop_length == k);
    }
    seen_index[node] = -1;
    // cerr << "leaving node " << node << " good: " << good << endl;
    return good;
}

int main() {
    fast;
    tests {
        ll n, k;
        cin >> n >> k;

        vector<ll> b(n);
        for (ll &i : b) cin >> i;

        for (int i = 0; i < n; ++i) {
            b[i]--;
        }

        bool good = true;
        if (k == 1) {

            for (int i = 0; i < n; ++i) {
                if (b[i] != i) {
                    good = false;
                    break;
                }
            }
        }
        else {
            vector<ll> seen_index(n, 0);

            for (int i = 0; i < n; ++i) {
                if (seen_index[i] == 0) {
                    good &= recurse(i, 1, b, seen_index, k);
                }
                if (!good) {
                    break;
                }
            }
        }




        cout << (good ? "YES" : "NO") << endl;






    }
}