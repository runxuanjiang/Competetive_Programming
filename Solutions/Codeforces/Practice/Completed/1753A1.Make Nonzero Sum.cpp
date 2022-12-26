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



        if (n % 2) {
            cout << -1 << endl;
        }
        else {
            vector<pair<int, int>> segs;
            for (int i = 0; i < n; i += 2) {
                if (a[i] == a[i+1]) {
                    segs.push_back({i+1, i+2});
                }
                else {
                    segs.push_back({i+1, i+1});
                    segs.push_back({i+2, i+2});
                }
            }
            cout << segs.size() << endl;
            for (auto i : segs) {
                cout << i.first << " " << i.second << endl;
            }

        }


    }


}