#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 0;
    cin >> t;
    for (int x = 0; x < t; ++x) {
        int l;
        cin >> l;
        vector<long long> nums(l);
        for (int i = 0; i < l; ++i) {
            cin >> nums[i];
        }
        bool equal = true;
        for (int i = 1; i < l; ++i) {
            if (nums[i] != nums.front()) {
                equal = false;
                break;
            }
        }
        if (equal) cout << l << endl;
        else cout << 1 << endl;
    }
}