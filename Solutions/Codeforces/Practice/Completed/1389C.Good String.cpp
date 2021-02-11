#include <bits/stdc++.h>

using namespace std;

char c[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int count = 0;
        string s;
        cin >> s;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                int tempcount = 0;
                for (auto ch : s) {
                    if (tempcount %2 == 0 && ch == c[i]) ++tempcount;
                    else if (tempcount % 2 == 1 && ch == c[j]) ++ tempcount;
                }
                if (c[i] != c[j] && tempcount % 2 == 1) --tempcount;
                count = max(count, tempcount);
            }
        }
        cout << s.length() - count << endl;
    }
}