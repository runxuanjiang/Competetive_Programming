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
        int n;
        cin >> n;

        vector<int> divisors;
        for (int i = 2; i <= n; ++i) {
            if (n % i == 0) divisors.push_back(i);
        }
        sort(divisors.begin(), divisors.end());

        if (divisors.size() == 3) {
            cout << 1 << endl;
            for (auto d : divisors) {
                cout << d << " ";
            }
        }
        else {
            vector<int> ans(divisors.size());
            ans[0] = divisors.front();
            int m = divisors.size() - 1;
            for (int i = 0; i < m; ++i) {
                if (divisors[i+1] % divisors[i] == 0) {
                    ans.push_back(divisors)
                }
            }
        }


        cout << endl;
    }
}