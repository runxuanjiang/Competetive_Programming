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


        ll sorted_up_to = -1;
        ll unsorted_since = -1;
        ll length = 0;
        bool good = true;


        for (auto i : s) {
            if (i == '+') {
                ++length;
            }
            if (i == '-') {
                --length;
                if (sorted_up_to != -1 && sorted_up_to + 1 > length) {
                    --sorted_up_to;
                }
                if (unsorted_since != -1 && unsorted_since + 1 > length) {
                    unsorted_since = -1;
                }
            }



            if (i == '0') {
                if (length < 2 || sorted_up_to + 1 == length) {
                    good = false;
                    break;
                }
                if (unsorted_since == -1) {
                    unsorted_since = length-1;
                }
                else {
                    unsorted_since = min(unsorted_since, length-1);
                }
            }
            if (i == '1') {
                if (unsorted_since != -1) {
                    good = false;
                    break;
                }
                sorted_up_to = length-1;
            }


        }

        cout << (good ? "YES" : "NO") << endl;




    }
}