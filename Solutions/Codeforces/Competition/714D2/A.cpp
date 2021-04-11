//Competition #:
//Problem #: A
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
        int n, k;
        cin >> n >> k;
        if (k > (n-1)/2) {
            cout << -1 << endl;;
        }
        else {
            vector<int> arr(n, 0);
            int max = n;
            int idx = 1;
            while (k--) {
                arr[idx] = max;
                idx += 2;
                --max;
            }

            int num = 1;

            for (int i = 0; i < arr.size(); ++i) {
                if (arr[i] == 0) {
                    arr[i] = num;
                    ++num;
                }
            }
            for (auto i : arr) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}