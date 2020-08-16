#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int count = 0;
        int n, m;
        cin >> n >> m;
        for (int j = 0; j < n-1; ++j) {
            string belt;
            cin >> belt;
            if (belt.back() != 'D') ++count;
        }
        string belt;
        cin >> belt;
        for (int j = 0; j < belt.size() - 1; ++j) {
            if (belt[j] != 'R') ++count;
        }
        cout << count << endl;
    }
}