//Competition #:
//Problem #: E
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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll sum = accumulate(a.begin(), a.end(), 0);
    // cerr << "sum is: " << sum << endl;
    bool canSeparate = false;
    bitset<300> elements;
    if (sum % 2 == 0) {
        vector<pair<bool, bitset<300>>> dp(90001);
        dp[0] = {true, bitset<300>()};
        for (int i = 0; i < n; ++i) {
            for (ll j = 0; j + a[i] <= 300*n; ++j) {
                if (dp[j].first && !dp[j].second[i] && !dp[j+a[i]].first) {
                    dp[j+a[i]] = {true, dp[j].second};
                    dp[j+a[i]].second.set(i, true);
                    // cerr << j+a[i] << " is completable with bitset " << dp[j+a[i]].second << endl;
                }
            }
        }

        if (dp[sum/2].first) {
            canSeparate = true;
            elements = dp[sum/2].second;
        }
    }

    if (canSeparate) {
        // cerr << "The following indexes add up to half the sum: ";
        // for (int i = 0; i < 300; ++i) {
        //     if (elements[i]) {
        //         cerr << i+1 << " ";
        //     }
        // }
        // cerr << endl;
        cout << "Second" << endl;

        ll response;
        cin >> response;
        while (response > 0) {
            ll idx1 = response - 1;
            bool inElements = elements[idx1];
            ll idx2;
            for (int i = 0; i < n; ++i) {
                if (a[i] && (elements[i] ^ inElements)) {
                    idx2 = i;
                    break;
                }
            }
            ll subtract = min(a[idx1], a[idx2]);
            a[idx1] -= subtract;
            a[idx2] -= subtract;
            cout << idx2+1 << endl;
            cin >> response;
        }

    }
    else {
        cout << "First" << endl;
        ll response = 1;
        while (response > 0) {
            ll idx1;
            for (int i = 0; i < n; ++i) {
                if (a[i]) {
                    idx1 = i;
                    break;
                }
            }
            cout << idx1 + 1 << endl;
            cin >> response;
            if (response > 0) {
                ll idx2 = response-1;
                ll subtract = min(a[idx1], a[idx2]);
                a[idx1] -= subtract;
                a[idx2] -= subtract;
            }
        }
    }
}