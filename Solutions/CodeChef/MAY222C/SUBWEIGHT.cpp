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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<vector<ll>> bounds(n, vector<ll>(4, -1));
        stack<ll> low, high;
        for (int i = 0; i < n; ++i) {
            while (!low.empty() && a[low.top()] > a[i]) {
                low.pop();
            }
            bounds[i][0] = (low.empty()) ? 0 : low.top() + 1;
            low.push(i);

            while (!high.empty() && a[high.top()] < a[i]) {
                high.pop();
            }
            bounds[i][2] = (high.empty()) ? 0 : high.top() + 1;
            high.push(i);
        }

        low = stack<ll>();
        high = stack<ll>();
        for (int i = n-1; i >= 0; --i) {
            while (!low.empty() && a[low.top()] > a[i]) {
                low.pop();
            }
            bounds[i][1] = (low.empty()) ? n-1 : low.top() - 1;
            low.push(i);

            while (!high.empty() && a[high.top()] < a[i]) {
                high.pop();
            }
            bounds[i][3] = (high.empty()) ? n-1 : high.top() - 1;
            high.push(i);            
        }

        ll res = 0;
        
        


    }
}