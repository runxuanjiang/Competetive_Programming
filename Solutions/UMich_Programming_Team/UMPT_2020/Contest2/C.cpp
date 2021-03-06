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
    int n;
    cin >> n;
    unordered_set<int> uniques;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t != 0) {
            uniques.insert(t);
        }
    }
    cout << uniques.size();
}