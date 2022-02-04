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
    vector<string> correct(3), guess(3);
    for (int i = 0; i < 3; ++i) {
        cin >> correct[i];
    }
    for (int i = 0; i < 3; ++i) {
        cin >> guess[i];
    }

    unordered_multiset<char> seen;
    int green = 0, yellow = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (correct[i][j] == guess[i][j]) {
                guess[i][j] = '.';
                ++green;
            }
            else {
                seen.insert(correct[i][j]);
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (seen.find(guess[i][j]) != seen.end()) {
                ++yellow;
                seen.erase(seen.find(guess[i][j]));
            }
        }
    }

    cout << green << endl;
    cout << yellow << endl;
}