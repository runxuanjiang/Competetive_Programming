//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    tests{
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> v(n, vector<ll>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> v[i][j];
            }
        }

        ll res = 0;

        for (int i = 0; i < (n+1)/2; ++i) {
            for (int j = 0; j < (m+1)/2; ++j) {
                int iopp = n - 1 - i;
                int jopp = m - 1 -j;
                vector<ll> nums;

                if (jopp==j && iopp == i) continue;
                else if (jopp == j && iopp != i) {
                    nums.push_back(v[i][j]);
                    nums.push_back(v[iopp][j]);
                }
                else if (iopp == i && jopp != j) {
                    nums.push_back(v[i][j]);
                    nums.push_back(v[i][jopp]);
                }
                else {
                    nums.push_back(v[i][j]);
                    nums.push_back(v[i][jopp]);
                    nums.push_back(v[iopp][j]);
                    nums.push_back(v[iopp][jopp]);
                }

                sort(nums.begin(), nums.end());
                ll med1 = nums[nums.size() / 2];
                ll med2 = nums[nums.size() / 2 - 1];
                ll res1 = 0, res2 = 0;
                for (auto i : nums) {
                    res1 += abs(i - med1);
                    res2 += abs(i - med2);
                }
                res += min(res1, res2);

            }
        }
        cout << res << endl;
    }
}