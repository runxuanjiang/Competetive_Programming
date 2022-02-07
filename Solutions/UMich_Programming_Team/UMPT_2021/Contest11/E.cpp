//Competition #:
//Problem #: E
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
    int n;
    cin >> n;


    set<int> seen;
    for (int i = 0; i < n; ++i) {
        int curr; 
        cin >> curr;
        
        if (seen.empty()) {
            cout << -1 << endl;
        }
        else {
            auto it = seen.lower_bound(curr);
            if (it == seen.begin()) {
                cout << -1 << endl;
            }
            else {
                --it;
                cout << *it << endl;
            }
        }

        seen.insert(curr);


    }
}