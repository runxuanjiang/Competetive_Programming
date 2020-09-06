//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        ll neg = 0;
        ll tempneg = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) neg += nums[i];
        }
        ll tot = -neg;
        ll res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                if (tempneg == 0) neg -= nums[i];
                else {
                    tempneg += nums[i];
                    if (tempneg < 0) {
                        neg -= tempneg;
                        tempneg -= tempneg;
                    }
                }
            }
            else if (nums[i] > 0) {
                ll subtract = min(nums[i], -neg);
                res += subtract;
                neg += subtract;
                tempneg += subtract;
            }
        }
        cout << tot - res << endl;
    }
}