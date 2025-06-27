//Competition #:
//Problem #: B
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

        if (k % 2 == 0) {
            sort(s.begin(), s.end());
            cout << s << endl;
        }
        else {
            string even, odd;
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) {
                    even += s[i];
                } else {
                    odd += s[i];
                }
            }

            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());

            for (int i = 0; i < n/2; ++i) {
                cout << even[i];
                cout << odd[i];
            }
            if (n % 2 == 1) {
                cout << even.back();
            }
            cout << endl;
        }





    }
}