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
    string t;
    cin >> t;

    string s = "";
    int plus = 1;
    for (int i = 0; i < n; i+= plus) {
        s += t[i];
        ++plus;
    }
    cout << s << endl;
}