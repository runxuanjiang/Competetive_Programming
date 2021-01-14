//Competition #: Codeforces Round 305 Div 1
//Problem #: B
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> orig(v.begin(), v.end());

    for (int i = 0; i < n; ++i) {
        int m = 0;
        for (int j = 0; j < n-i; ++j) {
            v[j] = min(v[j], orig[j+i]);
            m = max(m, v[j]);
        }
        cout << m << " ";
    }
}