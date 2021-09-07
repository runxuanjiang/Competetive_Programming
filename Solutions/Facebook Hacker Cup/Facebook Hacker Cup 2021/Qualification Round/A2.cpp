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

int testnum = 0;

int check(int i, const vector<int> &counts, const vector<vector<int>> &parents) {
    vector<int> steps(26, -1);
    steps[i] = 0;

    int stepid = 0;
    vector<int> curr = {i};
    vector<int> next;

    bool found = true;
    while (found) {
        ++stepid;
        found = false;
        next.clear();
        for (auto i : curr) {
            for (auto j : parents[i]) {
                if (steps[j] == -1) {
                    steps[j] = stepid;
                    found = true;
                    next.push_back(j);
                }

            }
        }

        swap(curr, next);
    }

    int res = 0;
    for (int i = 0; i < counts.size(); ++i) {
        if (counts[i] > 0) {
            if (steps[i] == -1) {
                return -1;
            }
            else {
                res += counts[i] * steps[i];
            }
        }
    }
    return res;

    
}

int main() {
    fast;
    tests {
        ++testnum;
        cout << "Case #" << testnum << ": ";

        string s;
        cin >> s;
        int k;
        cin >> k;
        vector<int> counts(26, 0);
        vector<vector<int>> parents(26);
        for (int i = 0; i < k; ++i) {
            char a, b;
            cin >> a >> b;
            parents[b - 'A'].push_back(a - 'A');
        }

        for (auto i : s) {
            counts[i-'A']++;
        }

        int res = -1;
        for (int i = 0; i < 26; ++i) {
            int tempres = check(i, counts, parents);
            if (tempres != -1) {
                if (res == -1) {
                    res = tempres;
                }
                else {
                    res = min(res, tempres);
                }
            }
        }

        cout << res << endl;
    }

}