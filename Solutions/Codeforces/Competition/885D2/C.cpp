//Competition #:
//Problem #: C
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ll calculate_zero_frequency(long long a, long long b) {
    if (a == 0 && b == 0) {
        return -1;
    }

    if (a == 0) {
        return 0;
    }
    if (b == 0) {
        return 1;
    }
    if (a == b) {
        return 2;
    }

    if (a < b) {
        return (1 + calculate_zero_frequency(b, b-a)) % 3;
    }

    ll iterations = (a/b);
    if (iterations % 2 == 0) {
        return (1 + calculate_zero_frequency(b, b - (a%b))) % 3;
    }
    else {
        return (1 + calculate_zero_frequency(b, a - (iterations) * b)) % 3;
    }


}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<bool> zero_frequencies(3, 0);
        for (int i = 0; i < n; ++i) {
            ll zero_frequency = calculate_zero_frequency(a[i], b[i]);
            cerr << zero_frequency << " ";
            if (zero_frequency >= 0) {
                zero_frequencies[zero_frequency] = true;
            }
        }
        cerr << endl;


        if (count(zero_frequencies.begin(), zero_frequencies.end(), true) > 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}