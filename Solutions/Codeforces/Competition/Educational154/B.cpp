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
        string a, b;
        cin >> a >> b;

        bool good = false;
        for (int i = 0; i + 1 < a.size(); ++i) {
            if (a[i] == '0' && b[i] == '0' && a[i+1] == '1' && b[i+1] == '1') {
                good = true;
                break;
            }
        }

        cout << (good ? "YES" : "NO") << endl;


    }
}