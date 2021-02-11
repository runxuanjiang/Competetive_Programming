//Competition #: Beta Round 89 (118A) 
//Problem #: A
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

unordered_set<char> VOWELS = {'a', 'o', 'y', 'e', 'u', 'i', 'A', 'O', 'Y', 'E', 'U', 'I'};

int main() {
    fast;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); ++i) {
        if (VOWELS.find(s[i]) != VOWELS.end()) {
            s.erase(s.begin() + i);
            --i;
        }
        else {
            s[i] = tolower(s[i]);
            s.insert(s.begin() + i, '.');
            ++i;
        }
    }

    cout << s << endl;


}