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
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    vector<int> out(n);
    for (int i = 0; i < n/2; ++i) {
        out[i*2 + 1] = v[i];
    }
    for (int i = n/2; i < n; ++i) {
        out[(i - n/2) * 2] = v[i];
    }
    int res = 0;

    for (int i = 1; i < out.size() - 1; ++i) {
        if (out[i] < out[i-1] && out[i] < out[i+1]) {
            ++res;
            ++i;
        }
    }

    cout << res << endl;
    for (auto i : out) {
        cout << i << " ";
    }
}