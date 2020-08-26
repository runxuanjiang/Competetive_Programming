#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; ++x) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string res = "";
        for (int i = 0; i < n; ++i) {
            res += s[2*i];
        }
        cout << res << endl;
    }
}