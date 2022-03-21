//Competition #:
//Problem #: B
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
        string s;
        cin >> s;

        unordered_map<char, int> counts;
        for (auto i : s) {
            if (counts.find(i) == counts.end()) {
                counts[i] = 0;
            }
            counts[i]++;
        }


        int idx = 0;
        while (idx < s.size()) {
            counts[s[idx]]--;
            if (!counts[s[idx]]) {
                break;
            }
            ++idx;
        }


        cout << s.substr(idx) << endl;
    }
}