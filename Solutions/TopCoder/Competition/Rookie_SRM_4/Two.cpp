//Competition #:
//Problem #:
//Accepted: YES

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

class MarblePicking {
public:
    int fewestColors(vector<string> marbles, int count) {
        if (count == 0) return 0;
        vector<int> counts(26, 0);
        for (auto m : marbles) {
            for (auto i : m) {
                counts[i - 'A']++;
            }
        }

        sort(counts.begin(), counts.end());
        int res = 0;
        for (int i = 25; i >= 0; --i) {
            ++res;
            count -= counts[i];
            if (count <= 0) break;
        }
        return res;
    }
};