//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

bool check(int l, int m, int r, const vector<vector<int>> &psum) {
    bool extra = false;

    vector<int> left(26, 0);
    vector<int> right(26, 0);


    for (int i = 0; i < 26; ++i) {
        left[i] = psum[m+1][i] - psum[l][i];
        right[i] = psum[r+1][i] - psum[m+1][i];
    }

    // for (auto i : left) {
    //     cout << i << " ";
    // }
    // cout << endl;

    // for (auto i : right) {
    //     cout << i << " ";
    // }
    // cout << endl;

    for (int i = 0; i < 26; ++i) {
        if (right[i]- left[i]) {
            if (abs(right[i]- left[i]) > 1) {
                return false;
            }
            else {
                if (extra) {
                    return false;
                }
                extra = true;
            }
        }
    }
    return extra;
}

int main() {
    fast;
    int test = 0;
    tests {
        ++test;
        cout << "Case #" << test << ": ";

        string s;
        cin >> s;

        ll q;
        cin >> q;

        ll res = 0;

        vector<vector<int>> psum(s.size() + 1, vector<int>(26, 0));

        for (int i = 0; i < s.size(); ++i) {
            psum[i+1] = psum[i];
            psum[i+1][s[i] - 'a']++;
        }


        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;

            if ((r-l+1) % 2 == 1) {
                int mid = l + (r-l)/2;

                if (check(l, mid, r, psum)) {
                    ++res;
                    continue;
                }

                if (check(l, mid-1, r, psum)) {
                    ++res;
                    continue;
                }


            }

            // cout << l << " " << r << " " << res << endl;

        }

        cout << res << endl;

    }
}