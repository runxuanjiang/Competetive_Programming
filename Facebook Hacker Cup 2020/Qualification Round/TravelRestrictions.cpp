#include <bits/stdc++.h>

using namespace std;

int main() {
    int airlines;
    cin >> airlines;
    unordered_map<int, int> forward;
    unordered_map<int, int> backward;
    for (int i = 0; i < airlines; ++i) {
        cout << "Case #" << i+1 << ": \n";
        int countries;
        string inbound;
        string outbound;
        cin >> countries >> inbound >> outbound;
        int start = 0;
        for (int j = 0; j < countries; ++j) {
            while (outbound[j] == 'N') {
                forward[j] = j;
                ++j;
            }
            start = j;
            while (j + 1 < countries && outbound[j] == 'Y' && inbound[j+1] == 'Y') {
                ++j;
            }
            for (int k = start; k <= j; ++k) {
                forward[k] = j;
            }
        }
        for (int j = countries - 1; j >= 0; --j) {
            while (outbound[j] == 'N') {
                backward[j] = j;
                --j;
            }
            start = j;
            while (j - 1 >= 0 && outbound[j] == 'Y' && inbound[j-1] == 'Y') {
                --j;
            }
            for (int k = start; k >= j; --k) {
                backward[k] = j;
            }
        }
        for (int j = 0; j < countries; ++j) {
            for (int k = 0; k < countries; ++k) {
                if (k < backward[j] || k > forward[j]) cout << 'N';
                else cout << 'Y';
            }
            cout << "\n";
        }
    }

}