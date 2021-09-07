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

set<char> vowels = {'A', 'E', 'I', 'O', 'U'};

int testnum = 0;

int main() {
    fast;
    tests {
        ++testnum;
        cout << "Case #" << testnum << ": ";
        string s;
        cin >> s;

        unordered_map<char, int> v, c;
        int numv = 0, numc = 0;
        for (auto i : s) {
            if (vowels.find(i) != vowels.end()) {
                ++numv;
                if (v.find(i) == v.end()) {
                    v[i] = 0;
                }
                ++v[i];
            }
            else {
                ++numc;
                if (c.find(i) == c.end()) {
                    c[i] = 0;
                }
                ++c[i];
            }
        }

        if (v.size() + c.size() <= 1) {
            cout << 0 << endl;
            continue;
        }
        
        int vmax = 0, cmax = 0;
        for (auto i : v) {
            vmax = max(vmax, i.second);
        }
        for (auto i : c) {
            cmax = max(cmax, i.second);
        }

        int cand1 = (numv - vmax)*2 + numc;
        int cand2 = (numc - cmax)*2 + numv;
        cout << min(cand1, cand2) << endl;




        

    }
}