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

int main() {
    fast;
    int n;
    cin >> n;
    unordered_set<string> seen;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        string uni, team;
        cin >> uni >> team;
        if (cnt < 12 && seen.find(uni) == seen.end()) {
            cout << uni << " " << team << endl;
            seen.insert(uni);
            ++cnt;
        }
    }
}