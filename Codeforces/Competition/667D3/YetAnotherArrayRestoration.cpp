//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        int sep = n-1, dist;
        for (; sep > 0; --sep) {
            if ((y-x) % sep == 0) {
                dist = (y-x) / sep;
                break;
            }
        }

        int start = (x % dist == 0) ? dist : x % dist;
        start = max(start, y-((n-1)*dist));

        for (int i = 0; i < n; ++i) {
            cout << start << " ";
            start += dist;
        } 
        cout << endl;

    }
}