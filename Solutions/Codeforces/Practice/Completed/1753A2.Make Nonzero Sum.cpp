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

int main() {
    fast;

    tests {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int nonzero = 0;
        for (auto i : a) {
            if (i != 0) {
                nonzero++;
            }
        }

        if (nonzero % 2) {
            cout << -1 << endl;
        }
        else {
            vector<pair<int, int>> res;
            for (int i = 0; i < n; ++i) {
                if (a[i]) {
                    int j = i+1;
                    while (!a[j]) {
                        ++j;
                    }

                    if (j == i+1) {
                        if (a[i] == a[j]) {
                            res.push_back({i+1, j+1});
                        }
                        else {
                            res.push_back({i+1, i+1});
                            res.push_back({j+1, j+1});
                        }
                    }
                    else {
                        res.push_back({i+1, i+1});
                        if (a[i] == a[j]) {
                            if (j - i > 2) {
                                res.push_back({i+2, j+1-2});
                            }
                            res.push_back({j+1-1, j+1});
                        }
                        else {
                            res.push_back({i+2, j+1-1});
                            res.push_back({j+1, j+1});
                        }
                    }
                    i = j;
                }
                else {
                    res.push_back({i+1, i+1});
                }
            }

            cout << res.size() << endl;
            for (auto i : res) {
                cout << i.first << " " << i.second << endl;
            }
        }


    }
}