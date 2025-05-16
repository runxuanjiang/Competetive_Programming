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

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll positives = 0, negatives = 0;
        ll min_element = a[0], min_idx = 0, max_element = a[0], max_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) {
                positives++;
            } else if (a[i] < 0) {
                negatives++;
            }
            if (a[i] < min_element) {
                min_element = a[i];
                min_idx = i;
            }
            if (a[i] > max_element) {
                max_element = a[i];
                max_idx = i;
            }
        }

        if (negatives == 0) {
            cout << n-1 << endl;
            for (int i = 2; i <= n; ++i) {
                cout << i << " " << i-1 << endl;
            }
        }
        else if (positives == 0) {
            cout << n-1 << endl;
            for (int i = n-1; i >= 1; --i) {
                cout << i << " " << i+1 << endl;
            }
        }
        else {
            ll positives_count = 0, negatives_count = 0;
            ll positive_doubler = max_element;
            while (positive_doubler < -min_element) {
                positive_doubler *= 2;
                ++positives_count;
            }
            positives_count += negatives;

            ll negatives_doubler = min_element;
            while (negatives_doubler > -max_element) {
                negatives_doubler *= 2;
                ++negatives_count;
            }
            negatives_count += positives;

            if (positives_count < negatives_count) {
                cout << positives_count + n - 1 << endl;
                positive_doubler = max_element;
                while (positive_doubler < -min_element) {
                    cout << max_idx+1 << " " << max_idx+1 << endl;
                    positive_doubler *= 2;
                }

                for (int i = 0; i < n; ++i) {
                    if (a[i] < 0) {
                        cout << i+1 << " " << max_idx+1 << endl;
                    }
                }

                for (int i = 2; i <= n; ++i) {
                    cout << i << " " << i-1 << endl;
                }


            }
            else {
                cout << negatives_count + n - 1 << endl;
                negatives_doubler = min_element;
                while (negatives_doubler > -max_element) {
                    cout << min_idx+1 << " " << min_idx+1 << endl;
                    negatives_doubler *= 2;
                }

                for (int i = 0; i < n; ++i) {
                    if (a[i] > 0) {
                        cout << i+1 << " " << min_idx+1 << endl;
                    }
                }

                for (int i = n-1; i >= 1; --i) {
                    cout << i << " " << i+1 << endl;
                }

            }
        }


    }
}