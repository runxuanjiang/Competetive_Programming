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
    fast;
    tests{
        ll n;
        cin >> n;
        vector<ll> pos;
        vector<ll> negs;

        for (int i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            if (a >= 0) pos.push_back(a);
            else negs.push_back(a);
        }

        sort(pos.begin(), pos.end());
        sort(negs.begin(), negs.end());

        ll res = 1;

        if (pos.size() + negs.size() == 5) {
            for (int i = 0; i < pos.size(); ++i) {
                res *= pos[i];
            }
            for (int i = 0; i < negs.size(); ++i) {
                res *= negs[i];
            }
            cout << res << endl;
        }

        else if (pos.size() == 0) {
            for (int i = negs.size() - 1; i >= negs.size() - 5; --i) {
                res *= negs[i];
            }
            cout << res << endl;
        }

        else {
            res = pos.back();
            int posI = pos.size() - 3;
            int negI = 0;

            for (int i = 0; i < 2; ++i) {
                if (posI >= 0 && (negI + 1 >= negs.size() || pos[posI] * pos[posI+1] > negs[negI] * negs[negI+1])) {
                    res *= (pos[posI] * pos[posI+1]);
                    posI -= 2;
                }
                else {
                    res *= (negs[negI] * negs[negI+1]);
                    negI += 2;
                }
            }
            cout << res << endl;
        }
    }
}