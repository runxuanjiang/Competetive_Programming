#include <bits/stdc++.h>

using namespace std;

int main() {
    int inputs;
    cin >> inputs;
    for (int i = 0; i < inputs; ++i) {
        bool zero = false;
        bool one = false;
        unsigned size;
        int temp;
        cin >> size;
        vector<unsigned> nums(size);
        for (int j = 0; j < size; ++j) {
            cin >> nums[j];
        }
        for (int j = 0; j < size; ++j) {
            cin >> temp;
            if (temp == 0) zero = true;
            else if (temp == 1) one = true;
        }
        if (zero && one) cout << "Yes" << endl;
        else {
            bool ordered = true;
            for (int j = 1; j < size; ++j) {
                if (nums[j] < nums[j-1]) {
                    ordered = false;
                    break;
                }
            }
            if (ordered) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}