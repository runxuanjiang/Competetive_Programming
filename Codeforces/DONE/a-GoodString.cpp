#include <bits/stdc++.h>

using namespace std;

unsigned cGood(char c, string str) {
    if (str.length() == 1) {
        if (str[0] == c) return 0;
        else return 1;
    }
    else {
        unsigned left = (str.length()/2 - count(str.begin(), str.begin() + (str.length() / 2), c)) + cGood(c + 1, str.substr(str.length() / 2));
        unsigned right = (str.length()/2 - count(str.begin() + (str.length() / 2), str.end(), c)) + cGood(c+1, str.substr(0, str.length() / 2));
        return min(left, right);
    }
}

int main() {
    unsigned testnum;
    cin >> testnum;
    for (int i = 0; i < testnum; ++i) {
        unsigned length;
        cin >> length;
        string str;
        cin >> str;
        cout << cGood('a', str) << endl;
    }
}