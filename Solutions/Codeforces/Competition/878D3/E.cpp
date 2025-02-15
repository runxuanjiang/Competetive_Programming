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

int main() {
    fast;
    tests {
        string s1, s2;
        cin >> s1;
        cin >> s2;

        ll t, q;
        cin >> t >> q;

        vector<bool> match(s1.size(), 0);
        vector<ll> blocked(s1.size(), 0);
        ll mismatchCount = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) {
                match[i] = true;
            }
            else {
                ++mismatchCount;
            }
        }
        
        map<ll, ll> checkBlocked;

        for (ll i = 1; i <= q; ++i) {
            ll qtype;
            cin >> qtype;

            if (checkBlocked.find(i) != checkBlocked.end()) {
                ll index = checkBlocked[i];
                if (blocked[index] <= i) {
                    blocked[index] = 0;
                    if (match[index] && s1[index] != s2[index]) {
                        match[index] = false;
                        ++mismatchCount;
                    }
                }
            }

            switch(qtype) {
                case 1: {
                    ll index;
                    cin >> index;
                    --index;

                    blocked[index] = i + t;
                    if (!match[index]) {
                        match[index] = true;
                        --mismatchCount;
                    }
                    checkBlocked[i+t] = index;
                    break;
                }
                case 2: {
                    ll string1, index1, string2, index2;
                    cin >> string1 >> index1 >> string2 >> index2;
                    --index1;
                    --index2;

                    if (string1 == 1) {
                        if (string2 == 1) {
                            swap(s1[index1], s1[index2]);
                        }
                        else if (string2 == 2) {
                            swap(s1[index1], s2[index2]);
                        }
                    }
                    else if (string1 == 2) {
                        if (string2 == 1) {
                            swap(s2[index1], s1[index2]);
                        }
                        else if (string2 == 2) {
                            swap(s2[index1], s2[index2]);
                        }
                    }

                    if (match[index1] && s1[index1] != s2[index1]) {
                        match[index1] = false;
                        ++mismatchCount;
                    }
                    else if (!match[index1] && s1[index1] == s2[index1]) {
                        match[index1] = true;
                        --mismatchCount;
                    }

                    if (match[index2] && s1[index2] != s2[index2]) {
                        match[index2] = false;
                        ++mismatchCount;
                    }
                    else if (!match[index2] && s1[index2] == s2[index2]) {
                        match[index2] = true;
                        --mismatchCount;
                    }
                    break;
                }
                case 3: {
                    cout << (mismatchCount == 0 ? "YES" : "NO") << endl;
                }
            }
        }
    

    }
}