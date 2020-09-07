//Competition #: 666 D2
//Problem #: D
//Acepted: Yes

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll m = 0;
        ll sum = 0;
        vector<ll> v;
        for (int i = 0; i < n; ++i) {
            ll in;
            cin >> in;
            m = max(m, in);
            sum += in;
        }

        if (m > (sum - m)) cout << "T" << endl;
        else {
            if (sum % 2 == 0) cout << "HL" << endl;
            else cout << "T" << endl;
        }
    }
}