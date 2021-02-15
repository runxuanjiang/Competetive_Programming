//Competition #:
//Problem #: A
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
        int n;
        cin >> n;
        int count = 0;
        int min = 200;
        for (int i = 0; i < n; ++i) {
            int in;
            cin >> in;
            if (in < min) {
                count = 1;
                min = in;
            }
            else if (in == min) {
                ++count;
            }
        }

        cout << n -count << endl;
    }
}