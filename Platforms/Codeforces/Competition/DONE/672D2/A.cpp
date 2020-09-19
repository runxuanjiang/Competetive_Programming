//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    tests {
        int n;
        cin >> n;
        string k;
        cin >> k;

        if (n % 2 == 0) {
            bool win2 = false;
            for (int i = 1; i < k.length(); i+=2) {
                if ((k[i] - '0') % 2 == 0) {
                    win2 = true;
                    break;
                }
            }
            if (win2) cout << 2 << endl;
            else cout << 1 << endl;
        }
        else {
            bool win1 = false;
            for (int i = 0; i < k.length(); i+=2) {
                if ((k[i] - '0') % 2 == 1) {
                    win1 = true;
                    break;
                }
            }
            if (win1) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
}