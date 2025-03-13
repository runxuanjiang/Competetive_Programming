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
        string s;
        cin >> s;

        ll m;
        cin >> m;
        string l, r;
        cin >> l >> r;


        bitset<300000> next;
        bitset<300000> prev;

        bool possible = false;

        for (char i = l[0]; i <= r[0]; ++i) {
            bool seen = false;
            for (int j = 0; j < s.size(); ++j) {
                if (s[j] == i) {
                    seen = true;
                    prev[j] = true;
                    break;
                }
            }

            if (!seen) {
                possible = true;
                break;
            }
        }

        // for (int i = 0; i < s.size(); ++i) {
        //     if (prev[i]) {
        //         cerr << i << " ";
        //     }
        // }
        // cerr << endl;


        if (!possible) {
            for (int i = 1; i < m; ++i) {

                for (char j = l[i]; j <= r[i]; ++j) {
                    bool hasPrevious = false;

                    for (int k = 0; k < s.size(); ++k) {
                        if (hasPrevious && s[k] == j) {
                            next[k] = true;
                            hasPrevious = false;
                        }

                        if (prev[k]) {
                            hasPrevious = true;
                        }
                    }


                    if (hasPrevious) {
                        possible = true;
                        break;
                    }
                }

                if (possible) {
                    break;
                }

                // for (int i = 0; i < s.size(); ++i) {
                //     if (prev[i]) {
                //         cerr << i << " ";
                //     }
                // }
                // cerr << endl;

                swap(prev, next);
                next.reset();
            }

        }


        cout << (possible ? "YES" : "NO") << endl;




    }
}