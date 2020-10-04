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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<vector<int>> chars(26);
    for (int i = 0; i < s.length(); ++i) {
        chars[(int) s[i] - 'a'].push_back(i);
    }

    unordered_set<int> removed;
    for (int i = 0; i < 26; ++i) {
        if (!k) break;
        for (auto j : chars[i]) {
            if (!k) break;
            removed.insert(j);
            --k;
        }
    }

    for (int i = 0; i < s.length(); ++i) {
        if (removed.find(i) == removed.end()) {
            cout << s[i];
        }
    }


}