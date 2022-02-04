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
        vector<int> a(4), b(4);
        for (int i = 0; i < 4; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < 4; ++i) {
            cin >> b[i];
        }

        int awin = 0;
        for (auto i : a) {
            for (auto j : b) {
                if (i > j) ++awin;
                else if (i < j) --awin;
            }
        }

        bool found = false;
        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 10; ++j) {
                for (int k = 1; k <= 10; ++k) {
                    for (int l = 1; l <= 10; ++l) {
                        int win1 = 0, win2 = 0;
                        for (auto e : a) {
                            if (i > e) ++win1;
                            else if (i < e) --win1;

                            if (j > e) ++win1;
                            else if (j < e) --win1;

                            if (k > e) ++win1;
                            else if (k < e) --win1;

                            if (l > e) ++win1;
                            else if (l < e) --win1;
                        }
                        for (auto e : b) {
                            if (i > e) ++win2;
                            else if (i < e) --win2;

                            if (j > e) ++win2;
                            else if (j < e) --win2;

                            if (k > e) ++win2;
                            else if (k < e) --win2;

                            if (l > e) ++win2;
                            else if (l < e) --win2;
                        }

                        if ((awin > 0 && win1 > 0 && win2 < 0) || (awin < 0 && win1 < 0 && win2 > 0)) {
                            found = true;
                        }

                    }
                }
            }
        }

        if (found) {
            cout << "yes" << endl;
        }
        else cout << "no" << endl;
    }
}