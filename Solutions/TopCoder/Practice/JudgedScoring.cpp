//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

class JudgedScoring{
public:
    int overallScore(vector<int> scores) {
        int res = 0;
        int mi = INT_MAX;
        int ma = -1;
        for (auto i : scores) {
            res += i;
            mi = min(mi, i);
            ma = max(ma, i);
        }
        return res - mi - ma;
    }
};
