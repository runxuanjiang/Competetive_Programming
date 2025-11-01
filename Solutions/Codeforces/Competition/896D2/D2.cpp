//Competition #:
//Problem #: G
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
        for (ll &i : a) cin >> i;

        ll sum = 0;
        for (ll i : a) sum += i;
        if (sum % n != 0) {
            cout << "No" << endl;
        }
        else {
            ll target = sum/n;
            vector<ll> positives(60, 0);
            vector<ll> negatives(60, 0);
            vector<ll> positive_special(60, 0);
            vector<ll> negative_special(60, 0);
            bool good = true;


            for (auto i : a) {
                if (i < target) {
                    ll base = 1;
                    ll exp = 0;
                    while (i+base <= target) {
                        base *= 2;
                        ++exp;
                    }

                    positives[exp]++;

                    ull diff = abs(i+base-target);
                    if (popcount(diff) > 1) {
                        good = false;
                        break;
                    }

                    ll exp2 = bit_width(diff)-1;
                    negatives[exp2]++;

                    ull diff2 = abs(target-i);
                    if (popcount(diff2) == 1) {
                        positive_special[exp]++;
                    }


                }
                else if (i > target) {
                    ll base = -1;
                    ll exp = 0;
                    while (i+base >= target) {
                        base *= 2;
                        ++exp;
                    }

                    negatives[exp]++;
                    ull diff = abs(i+base-target);
                    if (popcount(diff) > 1) {
                        good = false;
                        break;
                    }
                    ll exp2 = bit_width(diff)-1;
                    positives[exp2]++;

                    ull diff2 = abs(target-i);
                    if (popcount(diff2) == 1) {
                        negative_special[exp]++;
                    }
                }
            }


            for (int i = 59; i >= 1; --i) {
                // cerr << "i: " << i << " pos: " << positives[i] << " neg: " << negatives[i] << " pos_spec: " << positive_special[i] << " neg_spec: " << negative_special[i] << endl;
                if (positives[i] > negatives[i]) {
                    ll diff = positives[i] - negatives[i];
                    if (diff > positive_special[i]) {
                        good = false;
                        break;
                    }

                    positives[i] -= diff;
                    positives[i-1] += diff;
                    negatives[i-1] -= diff;
                }
                else if (negatives[i] > positives[i]) {
                    ll diff = negatives[i] - positives[i];
                    if (diff > negative_special[i]) {
                        good = false;
                        break;
                    }

                    negatives[i] -= diff;
                    negatives[i-1] += diff;
                    positives[i-1] -= diff;
                }
            }

            if (positives[0] != negatives[0]) {
                good = false;
            }

            cout << (good ? "Yes" : "No") << endl;

        }


    }
}