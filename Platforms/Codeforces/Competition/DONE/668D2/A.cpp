//Competition #: Codeforces Round 668 Division 2
//Problem #: A
//Accepted: Yes

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        for (auto i = nums.rbegin(); i != nums.rend(); ++i) {
            cout << *i << " ";
        }
        cout << endl;
    }
}