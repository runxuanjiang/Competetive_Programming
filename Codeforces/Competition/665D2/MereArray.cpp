#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; ++x) {
        int l;
        cin >> l;
        vector<int> nums(l);
        deque<int> sorted;
        int lowest = 1000000007;
        for (int i = 0; i < l; ++i) {
            cin >> nums[i];
            lowest = min(lowest, nums[i]);
        }
        for (int i = 0; i < l; ++i) {
            if (nums[i] % lowest == 0) {
                sorted.push_back(nums[i]);
                nums[i] = -1;
            }
        }
        sort(sorted.begin(), sorted.end());
        bool b = true;
        for (int i = 0; i < l; ++i) {
            if (nums[i] == -1) {
                nums[i] = sorted.front();
                sorted.pop_front();
            }
            if (i > 0 && nums[i] < nums[i-1]) {
                b = false;
                break;
            }
        }
        if (b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}