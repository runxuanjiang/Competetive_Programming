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

int casenum = 0;

int main() {
    fast;
    tests {
        ++casenum;
        cout << "Case #" << casenum << ": ";
        ll n, k;
        cin >> n >> k;
        vector<ll> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        unordered_set<ll> left, right;
        bool good = true;
        for (auto i : s) {
            if (left.find(i) != left.end() || left.size() == k) {
                if (right.find(i) != right.end() || right.size() == k) {
                    good = false;
                    break;
                }
                else {
                    right.insert(i);
                }
            }
            else {
                left.insert(i);
            }
        }

        if (good) {
             cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}