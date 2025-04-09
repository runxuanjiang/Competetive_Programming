//Competition #:
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

bool equal_vector(const vector<ll> &l, const vector<ll> &r) {
    if (l.size() != r.size()) return false;
    for (int i = 0; i < l.size(); ++i) {
        if (l[i] != r[i]) return false;
    }
    return true;
}


int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        ll sum_a = 0;
        ll sum_b = 0;
        for (int i = 0; i < n; i++) {
            sum_a += a[i];
            sum_b += b[i];
        }

        ll diff = sum_a - sum_b;

        if (diff == 0) {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            ll res = a.back() + 1;
            for (int i = 0; i < n; ++i) {
                if (a[i] != b[i]) {
                    res = -1;
                }
            }
            cout << res << endl;
        }
        else if (diff < 0) {
            cout << -1 << endl;
        }
        else  {
            ll res = -1;
            unordered_set<ll> modulos;
            unordered_map<ll, ll> modulo_to_index;
            for (const auto i : b) {
                modulos.insert(i);
            }

            vector<ll> counts(modulos.size(), 0);
            ll index = 0;
            for (auto i : modulos) {
                modulo_to_index[i] = index;
                ++index;
            }

            for (const auto i : b) {
                counts[modulo_to_index[i]]++;
            }

            for (ll i = 1; i*i <= diff; ++i) {
                if (diff % i == 0) {
                    vector<ll> temp_counts1(counts.size(), 0), temp_counts2(counts.size(), 0);
                    
                    for (const auto j : a) {
                        if (modulo_to_index.find(j%i) != modulo_to_index.end()) {
                            temp_counts1[modulo_to_index[j%i]]++;
                        }
                        if (modulo_to_index.find(j%(diff/i)) != modulo_to_index.end()) {
                            temp_counts2[modulo_to_index[j%(diff/i)]]++;
                        }
                    }

                    if (equal_vector(counts, temp_counts1)) {
                        res = i;
                        break;
                    }

                    if (equal_vector(counts, temp_counts2)) {
                        res = diff / i;
                        break;
                    }



                }

            }
            cout << res << endl;
        }
    }
}