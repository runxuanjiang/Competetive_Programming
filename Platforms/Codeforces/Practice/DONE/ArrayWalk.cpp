#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; ++i) {
        int n, k, z;
        cin >> n >> k >> z;
        unsigned greedysum = 0;
        vector<unsigned> nums(n);
        vector<unsigned> csum(n);
        for (int j = 0; j < n; ++j) {
            cin >> nums[j];
            if (j == 0) csum[j] = nums[j];
            else csum[j] = nums[j] + csum[j-1];
        }
        unsigned sum = nums[0];
        for (int j = 1; j < k+1; ++j) {
            sum += nums[j];
            if (j == k) {
                greedysum = max(greedysum, sum);
            }
            else if (j > 0 && nums[j-1] > nums[j+1]) {
                int swapsteps = min(k-j, z*2);
                if (swapsteps % 2 != 0) {
                    greedysum = max(greedysum, nums[j-1] * (swapsteps / 2 + 1) + nums[j] * (swapsteps/2) + csum[j]);
                }
                else {
                    greedysum = max(greedysum, nums[j-1] * (swapsteps/2) + nums[j] * (swapsteps/2) + csum[k-swapsteps]);
                }
            }
        }
        cout << greedysum << endl;
    }
}