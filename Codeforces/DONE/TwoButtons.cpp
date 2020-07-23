#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long n, m;
    cin >> n >> m;

    if (n >= m) cout << (unsigned long long) n - m;
    else {
        unsigned long long count = 0;
        while (m > n) {
            if (m % 2 == 0) {
                m/= 2;
            }
            else m += 1;
            ++count;
        }
        cout << count + (n - m);
    }
}