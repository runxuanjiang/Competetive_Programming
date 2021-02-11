#include <bits/stdc++.h>

using namespace std;

int main() {
    int length;
    cin >> length;
    long long sum = 0;
    vector<long long> nums(length);
    for (int i = 0; i < length; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }
    if (sum % 3 != 0) {
        cout << 0;
    }
    else {
        vector<long long> count(length, 0);
        long long tempsum = 0;
        for (int i = length - 1; i>=0; --i) {
            tempsum += nums[i];
            if (tempsum == sum/3) {
                count[i] = 1;
            }
            if (i < length - 1) count[i] += count[i+1];

        }
        tempsum = 0;
        long long ans = 0;
        for (int i = 0; i < length - 2; ++i) {
            tempsum += nums[i];
            if (tempsum == sum/3) ans += count[i+2];
        }
        cout << ans;
    }
}