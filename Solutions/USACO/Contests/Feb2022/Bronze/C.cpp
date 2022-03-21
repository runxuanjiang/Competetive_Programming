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
    int n;
    cin >> n;
    
    vector<string> b(4);
    for (int i = 0; i < 4; ++i) {
        cin >> b[i];
    }

    int x = 0;
    LOOP: for (; x < n; ++x) {
        string word;
        cin >> word;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    for (int l = 0; l < 4; ++l) {
                        if (i != j && j != k && k != l && i != k && i != l && j != l) {
                            if (b[i].find(word[0]) != string::npos &&
                                (word.size() < 2 || b[j].find(word[1]) != string::npos) && 
                                (word.size() < 3 || b[k].find(word[2]) != string::npos) &&
                                (word.size() < 4 || b[l].find(word[3]) != string::npos)) {
                                    cout << "YES" << endl;
                                    ++x;
                                    goto LOOP;
                                }
                        }
                    }
                }
            }
        }

        cout << "NO" << endl;
    }
}