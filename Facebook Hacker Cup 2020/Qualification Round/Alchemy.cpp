#include <bits/stdc++.h>

using namespace std;

bool solve(string s, unordered_map<string, bool> &dp) {
    if (s.length() == 1) return true;
    if (dp.find(s) != dp.end()) return dp[s];
    for (int i = 1; i < s.length() - 1; ++i) {
        if (s[i-1] != s[i] || s[i+1] != s[i]) {
            string updated = s;
            unsigned short amber = 0, blue = 0;
            if (s[i-1] == 'A') ++amber;
            else ++blue;
            if (s[i] == 'A') ++amber;
            else ++blue;
            if (s[i+1] == 'A') ++amber;
            else ++blue;
            if (blue > amber) {
                updated.replace(i - 1, 3, "B");
            }
            else updated.replace(i-1, 3, "A");
            if (solve(updated, dp)) {
                dp[s] = true;
                return true;
            }
        }
    }
    dp[s] = false;
    return false;
}

int main() {
    int stones;
    cin >> stones;
    for (int i = 0; i < stones; ++i) {
        int length;
        unordered_map<string, bool> dp;
        string seq;
        cin >> length >> seq;
        unsigned A = 0, B = 0;
        for (auto c : seq) {
            if (c == 'A') ++A;
            else ++B;
        }
        if (A < seq.length() / 2 || B<seq.length() / 2) cout << "Case #" << i+1 << ": N\n";
        else cout << "Case #" << i+1 << ": Y\n";
    }
}