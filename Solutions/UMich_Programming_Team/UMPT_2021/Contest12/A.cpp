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
    int n;
    cin >> n;

    int g = -1, s = -1, b = -1;
    string country = "";
    for (int i = 0; i < n; ++i) {
        int gt, st, bt;
        cin >> gt >> st >> bt;
        string curr;
        getline(cin >> ws, curr);

        if (gt > g) {
            g = gt;
            s = st;
            b = bt;
            country = curr;
        }
        else if (gt == g) {
            if (st > s) {
                g = gt;
                s = st;
                b = bt;
                country = curr;
            }
            else if (st == s) {
                if (bt > b) {
                    g = gt;
                    s = st;
                    b = bt;
                    country = curr;
                }
            }
        }
    }
    cout << country << endl;
}