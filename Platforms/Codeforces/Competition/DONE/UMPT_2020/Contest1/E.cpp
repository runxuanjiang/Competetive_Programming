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

bool isPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l;
        --r;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }

    bool palindromeFound = false;
    string palindrome = "";
    unordered_set<string> missing;
    vector<string> out;
    int count = 0;

    for (auto s : strings) {
        if (!palindromeFound && isPalindrome(s)) {
            palindromeFound = true;
            palindrome = s;
            count += s.length();
        }
        if (missing.find(s) != missing.end()) {
            out.push_back(s);
            missing.erase(s);
            count += s.length() * 2;
        }
        else {
            string reversed(s.rbegin(), s.rend());
            missing.insert(reversed);
        }
    }

    cout << count << endl;

    for (int i = 0; i < out.size(); ++i) {
        cout << out[i];
    }
    if (palindromeFound) cout << palindrome;
    for (int i = out.size() - 1; i >=0; --i) {
        string rev(out[i].rbegin(), out[i].rend());
        cout << rev;
    }




}