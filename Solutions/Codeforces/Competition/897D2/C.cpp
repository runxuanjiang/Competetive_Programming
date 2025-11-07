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
        vector<ll> s(n);
        for (ll &i : s) cin >> i;

        sort(s.begin(), s.end());

        map<ll, ll> intervals;

        if (s.front() != 0) {
            intervals.insert({0, s.front() - 1});
        }

        for (int i = 0; i < n; ++i) {
            int start = i;
            while (start+1 < n && s[start+1] == s[start]+1) {
                ++start;
            }

            ll next = 1e9+1;
            if (start+1 < n) {
                next = s[start+1]-1;
            }
            intervals.insert({s[start]+1, next});
            i = start;
        }


        while (true) {
            cout << intervals.begin()->first << endl;
            ll response;
            cin >> response;

            if (response == -1) {
                break;
            }
            else if (response == -2) {
                return 0;
            }
            else {
                intervals.insert({response, response});
            }
        }

    }
}