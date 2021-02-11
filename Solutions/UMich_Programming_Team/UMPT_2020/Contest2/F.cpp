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

ll n, k;
void undo(vector<int> &in, int l, int r) {
    if (k < 1 || l == r-1) return;
    k -=2;
    int mid = (l+r)/2;
    swap(in[mid-1], in[mid]);
    undo(in, l, mid);
    undo(in, mid, r);
}

int main() {
    cin >> n >> k;
    if (k % 2 == 0) {
        cout << -1;
        return 0;
    }
    --k;
    vector<int> in(n);
    for (int i = 0; i < n; ++i) {
        in[i] = i+1;
    }
    undo(in, 0, n);
    if (k > 0) cout << -1;
    else {
        for (auto i : in) {
            cout << i << " ";
        }
    }
}