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

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        vector<ll> toleft(n+1, 0);
        vector<ll> toright(n+1, 0);

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                int j = i;
                int count = 1;
                while (i+1 < n && s[i+1] != s[i]) {
                    ++count;
                    ++i;
                }
                for (; j < n; j+=2) {
                    toright[j] = count;
                    count -= 2;
                    if (count <= 0) break;
                }
            }
        }

        for (int i = n-1; i >= 0; --i) {
            if (s[i] == 'L') {
                int j = i;
                int count = 1;
                while (i-1 >= 0 && s[i-1] != s[i]) {
                    ++count;
                    --i;
                }
                for (; j >= 0; j -=2) {
                    toleft[j] = count;
                    count -= 2;
                    if (count <= 0) break;
                }
            }
        }

        for (int i = 0; i < n+1; ++i) {
            int right = (i == n) ? 0 : toright[i];
            int left = (i == 0) ? 0 : toleft[i-1];
            cout << right + left + 1 << " ";
        }
        cout << endl;

    }
}