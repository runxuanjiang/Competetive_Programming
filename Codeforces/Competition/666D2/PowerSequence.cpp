//Competition #: 666 Div 2
//Problem #: B
//Acepted: Yes

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// int main() {
//     int n;
//     cin >> n;
//     vector<ull> v(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> v[i];
//     }
//     sort(v.begin(), v.end());

//     ull res1 = 0, res2 = 0;
//     ull base1 = floor(pow((ld) v.back(), (ld) 1/(ld) (n-1)));
//     ull base2 = ceil(pow((ld) v.back(), (ld) 1/(ld) (n-1)));

//     ull start1 = 1;
//     ull start2 = 1;
//     for (int i = 0; i < n; ++i) {
//         res1 += (v[i] > start1) ? (v[i] - start1) : (start1 - v[i]);
//         res2 += (v[i] > start2) ? (v[i] - start2) : (start2 - v[i]);
//         start1 *= base1;
//         start2 *= base2;
//     }
//     cout << min(res1, res2);
// }

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
 
    ll res = 0;
    ll base = floor(pow((ld) v.back(), (ld) 1/(ld) (n-1)));
    ll start = 1;
    for (int i = 0; i < n; ++i) {
        res += max(v[i] - start, start-v[i]);
        start *= base;
    }

    ll res1 = 0;
    ll base1 = ceil(pow((ld) v.back(), (ld) 1/(ld) (n-1)));
    ll start1 = 1;
    for (int i = 0; i < n; ++i) {
        res1 += max(v[i] - start1, start1 - v[i]);
        start1*=base1;
        if (res1 > res) {
            cout << res;
            return 0;
        }
    }
    cout << min(res, res1);
}