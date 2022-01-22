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
    unordered_set<int> us;
    for (int i = 1; i <= n; ++i) {
        us.insert(i);
    }

    for (int i = 0; i+1 < n; ++i) {
        int a;
        cin >> a;
        us.erase(a);
    }

    cout << *us.begin() << endl;
}