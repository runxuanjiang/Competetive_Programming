//Competition #: Educational Round 94
//Problem #: D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Track{
    int cnt = 0;
    int lastid = 0;
    vector<int> ic;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        ll res = 0;
        unordered_map<int, ll> left;
        for (int i = 0; i < n; ++i) {

            unordered_map<int, ll> right;
            for (int j = n-1; j > i; --j) {
                ll l = (left.find(v[j]) == left.end()) ? 0 : left[v[j]];
                ll r = (right.find(v[i]) == right.end()) ? 0 : right[v[i]];
                res += l*r;

                if (right.find(v[j]) == right.end()) right[v[j]] = 1;
                else ++right[v[j]];
            }
            if (left.find(v[i]) == left.end()) left[v[i]] = 1;
            else ++left[v[i]];
        }
        cout << res << endl;
    }
}