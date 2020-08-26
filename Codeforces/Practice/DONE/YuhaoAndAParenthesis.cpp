//Competition #: Hello 2019
//Problem #: C

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> cnt;
    int res = 0;


    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        
        int leftp = 0;
        int rightp = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') ++leftp;
            else leftp = max(0, leftp-1);
        }
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') ++rightp;
            else rightp = max(0, rightp-1);
        }

        if (leftp == 0 && rightp == 0) {
            if (cnt.find(0) == cnt.end() || cnt[0] == 0) cnt[0] = 1;
            else {
                --cnt[0];
                ++res;
            }
        }
        else if (leftp != 0 && rightp == 0) {
            if (cnt.find(-leftp) == cnt.end() || cnt[-leftp] == 0) {
                if (cnt.find(leftp) == cnt.end()) cnt[leftp] = 1;
                else ++cnt[leftp];
            }
            else {
                --cnt[-leftp];
                ++res;
            }
        }
        else if (rightp != 0 && leftp == 0) {
            if (cnt.find(rightp) == cnt.end() || cnt[rightp] == 0) {
                if (cnt.find(-rightp) == cnt.end()) cnt[-rightp] = 1;
                else ++cnt[-rightp];
            }
            else {
                --cnt[rightp];
                ++res;
            }
        }
    }
    cout << res << endl;
}