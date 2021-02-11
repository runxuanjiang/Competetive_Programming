//Competition #:
//Problem #: B
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
        int x;
        cin >> x;
        vector<int> a = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        set<int> digits;
        int sum = 0;
        bool found = false;

        for (int i = 0; i < 9; ++i) {
            if (sum + a[i] >= x) {
                cout << x - sum;
                for (auto j : digits) {
                    cout << j;
                }

                found = true;
                break;
            }
            else {
                sum += a[i];
                digits.insert(a[i]);
            }
        }

        if (!found) {
            cout << -1;
        }
        cout << endl;
        
    }
}