//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, s;
        cin >> n >> s;
        int csum = 0;
        string num = to_string(n);
        string cumulative = "";

        int tsum = 0;
        for (auto i : num) {
            tsum += (int)(i-48);
        }

        if (tsum <= s) cout << 0 << endl;
        else {
            for (auto i : num) {
                if (csum + 1 + (int) (i-48) > s) {
                    break;
                }
                else {
                    csum += (int)(i-48);
                    cumulative += i;
                }
            }
            // cout << cumulative << endl;
            ll cumulativeNum = (cumulative == "") ? 1 : stoll(cumulative) + 1;
            for (int i = 0; i < (num.length() - cumulative.length()); ++i) {
                cumulativeNum *= (ll) 10;
            }
            cout << cumulativeNum - n << endl;
        }

    }
}