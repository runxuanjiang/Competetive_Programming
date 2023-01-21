//Competition #:
//Problem #: C
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
        ll n;
        cin >> n;
        string s;
        cin >> s;

        vector<ll> count(26, 0);
        for (auto i : s) {
            count[i - 'a']++;
        }

        ll res = 0;
        string ans = "";


        for (int i = 1; i <= 26; ++i) {
            if (n % i == 0) {
                set<pair<ll, char>> sorted;
                unordered_set<char> unused;
                for (int i = 0; i < 26; ++i) {
                    sorted.insert({count[i], 'a' + i});
                }
                while (sorted.size() > i) {
                    unused.insert(sorted.begin()->second);
                    sorted.erase(sorted.begin());
                }

                vector<ll> remaining(count.begin(), count.end());

                

                ll target = n / i;
                ll tempres = 0;
                string curr = s;
                for (int j = 0; j < n; ++j) {
                    if (unused.find(curr[j]) != unused.end() || remaining[curr[j] - 'a'] > target) {
                        ++tempres;
                        --remaining[curr[j] - 'a'];
                        char add = sorted.begin()->second;
                        sorted.erase(sorted.begin());
                        remaining[add - 'a']++;
                        sorted.insert({remaining[add - 'a'], add});
                        curr[j] = add;
                    }
                }

                if (ans == "" || tempres < res) {
                    res = tempres;
                    ans = curr;
                }


            }
        }

        cout << res << endl;
        cout << ans << endl;
    }
}