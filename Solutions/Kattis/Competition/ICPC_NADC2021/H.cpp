//Competition #:
//Problem #: H
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

struct comp{
    bool operator() (const string &l, const string &r) {
        return (l.length() < r.length());
    }
};

int main() {
    fast;
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }

    sort(strings.begin(), strings.end(), comp());
    int res = 0;

    for (int i = 0; i < strings[0].length(); ++i) {
        for (int j = i+1; j <= strings[0].length(); ++j) {
            if (j - i <= res) continue;
            string t = strings[0].substr(i, j-i);

            // preprocess for kmp
            vector<int> pattern(t.length(), 0);
            for (int k = 1; k < t.length(); ++k) {
                int l = pattern[k-1];
                while (l > 0 && t[k] != t[l]) {
                    l = pattern[l-1];
                }
                if (t[k] == t[l]) ++l;
                pattern[k] = l;
            }

            bool works = true;
            for (auto str : strings) {
                bool found = false;
                for (int k = 0, l = 0; k < str.length(); ++k) {
                    while (l > 0 && t[l] != str[k]) {
                        l = pattern[l-1];
                    }
                    if (t[l] == str[k]) ++l;
                    if (l == t.length()) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    works = false;
                    break;
                }
            }
            if (works) {
                res = max(res, (int)t.length());
            }
        }
    }
    cout << res << endl;
    
}