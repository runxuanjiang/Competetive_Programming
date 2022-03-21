//Competition #:
//Problem #: B
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
    int n;
    cin >> n;
    ll x, y;
    cin >> x >> y;

    vector<ll> xn(n), yn(n);
    for (int i = 0; i < n; ++i) {
        cin >> xn[i];
        cin >> yn[i];
    }

    vector<unordered_map<ll, unordered_map<ll, unordered_set<ll>> > > hist((n+1)/2);

    vector<ll> res(n, 0);

    for (int i = 0; i < (n+1)/2; ++i) {
        // cout << "ITERATION " << i << endl;
        if (!i) {
            for (int j = 0; j < n; ++j) {
                hist[i][xn[j]][yn[j]].insert(1ll << j);
                // cout << xn[j] << " " << yn[j] << endl;
                if (xn[j] == x && yn[j] == y) {
                    res[i]++;
                }
            }
        }
        else {
            for (int j = 0; j < n; ++j) {
                for (auto coord1 : hist[i-1]) {
                    for (auto coord2 : coord1.second) {
                        ll newx = xn[j] + coord1.first, newy = yn[j] + coord2.first;
                        if (abs(newx) < 1000000001 && abs(newy) < 1000000001) {
                            for (auto seen : coord2.second) {
                                if ((seen & (1ll << j)) == 0 && hist[i][newx][newy].find(seen | (1ll << j)) == hist[i][newx][newy].end()) {
                                    // cout << newx << " " << newy << " ";
                                    // cout << "{";
                                    // for (int val = 0; val < n; ++val) {
                                    //     if ((1ll << val) & (seen | (1ll << j))) {
                                    //         cout << val+1 << " ";
                                    //     }
                                    // }
                                    // cout << "}" << endl;
                                    hist[i][newx][newy].insert(seen | (1ll << j));
                                    if (newx == x && newy == y) {
                                        // cout << "cheers" << endl;
                                        res[i]++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = (n+1)/2; i < n; ++i) {
        // cout << "ITERATION " << i << endl;
        int right = (n+1)/2 - 1;
        int left = i - right - 1;
        unordered_set<ll> seen;
        for (auto coord1l : hist[left]) {
            for (auto coord2l : coord1l.second) {
                for (auto coord1r : hist[right]) {
                    for (auto coord2r : coord1r.second) {
                        ll newx = coord1l.first + coord1r.first, newy = coord2l.first + coord2r.first;
                        if (newx == x && newy == y) {
                            for (auto setl : coord2l.second) {
                                for (auto setr : coord2r.second) {
                                    // cout << "{";
                                    // for (int val = 0; val <= n; ++val) {
                                    //     if ((1ll << val) & (setl)) {
                                    //         cout << val+1 << " ";
                                    //     }
                                    // }
                                    // cout << "}" << endl;
                                    // cout << "{";
                                    // for (int val = 0; val <= n; ++val) {
                                    //     if ((1ll << val) & (setr)) {
                                    //         cout << val+1 << " ";
                                    //     }
                                    // }
                                    // cout << "}" << endl; 
                                    if ((setl & setr) == 0 && seen.find(setl | setr) == seen.end()) {
                                        // cout << "cheers" << endl;
                                        // cout << "{";
                                        // for (int val = 0; val <= n; ++val) {
                                        //     if ((1ll << val) & (setl | setr)) {
                                        //         cout << val+1 << " ";
                                        //     }
                                        // }
                                        // cout << "}" << endl;
                                        res[i]++;
                                        seen.insert(setl | setr);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (auto i : res) {
        cout << i << endl;
    }
}