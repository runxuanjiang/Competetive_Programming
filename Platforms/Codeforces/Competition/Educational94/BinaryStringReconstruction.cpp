#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; ++x) {
        string s;
        cin >> s;
        int n;
        cin >> n;

        string r(s.length(), '1');

        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                if (i < s.length() - n) {
                    r[i+n] = '0';
                }
                if (i >= n) {
                    r[i-n] = '0';
                }
            }
        }
        bool works = true;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                if ((i<n || r[i-n] == '0') && (i >= s.length() - n || r[i+n] == '0')) {
                    works = false;
                    break;
                }
            }
        }
        if (works) {
            cout << r << endl;
        }
        else cout << -1 << endl;
    }
}