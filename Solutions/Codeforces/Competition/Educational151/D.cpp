//Competition #:
//Problem #: D
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

        vector<ll> ratingWithZeroLowerBound(n, 0);
        ll negatives = min(0ll, a.back());
        for (int i = n-1; i >= 0; --i) {
            if (i == n-1) {
                ratingWithZeroLowerBound[i] = max(0ll, a[i]);
            }
            else {
                negatives += a[i];
                if (negatives <= 0) {
                    ratingWithZeroLowerBound[i] = ratingWithZeroLowerBound[i+1];
                }
                else {
                    ratingWithZeroLowerBound[i] = negatives + ratingWithZeroLowerBound[i+1];
                    negatives = 0;
                }
            }
        }


        ll k = 0;
        ll currentMax = ratingWithZeroLowerBound[0];
        ll currentSum = 0;
        // cerr << "(currentMax, k)" << currentMax << " " << k << endl;
        for (int i = 0; i+1 < n; ++i) {
            currentSum += a[i];
            // cerr << "(currentSum, ratingWithZeroLowerBound[i+1])" << currentSum << " " << ratingWithZeroLowerBound[i+1] << endl;
            if (currentSum + ratingWithZeroLowerBound[i+1] > currentMax) {
                currentMax = currentSum + ratingWithZeroLowerBound[i+1];
                k = currentSum;
            }
        }

        cout << k << endl;

        
    }
}