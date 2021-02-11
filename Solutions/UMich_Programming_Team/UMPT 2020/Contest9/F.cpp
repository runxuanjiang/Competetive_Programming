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

int main() {
    fast;
    tests {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        ll cost = 0;
        if (k % 2 == 1) {
            unordered_map<char, ll> chars;
            for (int i = k/2; i < s.length(); i += k) {
                if (chars.find(s[i]) == chars.end()) {
                    chars[s[i]] = 1;
                }
                else {
                    chars[s[i]] += 1;
                }
            }
            ll m = 0;
            for (auto i : chars) {
                m = max(i.second, m);
            }
            cost += ((n/k) - m);
        }

        for (int i = 0; i < k/2; ++i) {
            unordered_map<char, ll> chars;
            for (int j = i; j < s.length(); j += k) {
                if (chars.find(s[j]) == chars.end()) {
                    chars[s[j]] = 1;
                }
                else chars[s[j]] += 1;
            }

            for (int j = k-i-1; j < s.length(); j+= k) {
                if (chars.find(s[j]) == chars.end()) {
                    chars[s[j]] = 1;
                }
                else chars[s[j]] += 1;
            }
            ll m = 0;
            for (auto i : chars) {
                m = max(i.second, m);
            }
            cost += (2*(n/k) - m);

        }

        cout << cost << '\n';
    }
}