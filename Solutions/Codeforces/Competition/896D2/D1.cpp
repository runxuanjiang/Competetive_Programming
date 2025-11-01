//Competition #:
//Problem #: D
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
        for (auto &i : a) {
            cin >> i;
        }

        ll sum = 0;
        for (ll i : a) {
            sum += i;
        }

        if (sum % n != 0) {
            cout << "No" << endl;
        }
        else {
            ll target = sum / n;
            unordered_map<ll, ll> counts;

            bool good = true;

            for (auto i : a) {
                if (i < target) {
                    ll diff = 1;
                    while (i+diff <= target) {
                        diff *= 2;
                    }

                    ll diff2 = i+diff-target;
                    if (popcount((ull) diff2) > 1) {
                        good = false;
                        break;
                    }

                    counts[diff]++;
                    counts[-diff2]++;

                }
                else if (i > target) {
                    ll diff = 1;
                    while (i-diff >= target) {
                        diff *= 2;
                    }

                    ll diff2 = target - (i-diff);
                    if (popcount((ull) diff2) > 1) {
                        good = false;
                        break;
                    }

                    counts[-diff]++;
                    counts[diff2]++;

                }
            }

            for (const auto& i : counts) {
                if (counts[-i.first] != i.second) {
                    good = false;
                    break;

                }
            }
            
            cout << (good ? "Yes" : "No") << endl;
        }


    }
}