//Competition #: 666 D2
//Problem #: A
//Acepted: Yes

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<char, int> m;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (char c : s) {
                if (m.find(c) == m.end()) m[c] = 1;
                else ++m[c];
            }
        }
        bool b = true;
        for (auto p : m) {
            if (p.second % n != 0) {
                b = false;
                break;
            }
        }
        if (b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}