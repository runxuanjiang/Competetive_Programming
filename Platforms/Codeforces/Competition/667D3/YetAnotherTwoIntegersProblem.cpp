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
        ll a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);

        cout << (ll) ceil((long double) (b-a) / (long double) 10) << endl;
    }
}