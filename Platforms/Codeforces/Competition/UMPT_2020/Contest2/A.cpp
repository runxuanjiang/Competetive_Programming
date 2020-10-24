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

        vector<int> ans;
        string s = to_string(n);
        for (int i = 0; i < s.length(); ++i) {
            if (s[s.length() - 1 - i] != '0') {
                ans.push_back( pow(10, i) * (int) ( s[s.length() - 1 - i] - '0') );
            }
        }
        cout << ans.size() << endl;
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}