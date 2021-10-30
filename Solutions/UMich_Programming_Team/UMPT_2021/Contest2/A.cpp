//Competition #:
//Problem #: A
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
    string s;
    cin >> s;

    vector<bool> rooms(10, false);

    for (auto i : s) {
        if (i == 'L') {
            for (int i = 0; i < 10; ++i) {
                if (!rooms[i]) {
                    rooms[i] = true;
                    break;
                }
            }
        }
        else if (i == 'R') {
            for (int j = 9; j >= 0; --j) {
                if (!rooms[j]) {
                    rooms[j] = true;
                    break;
                }
            }
        }
        else {
            rooms[i - '0'] = false;
        }
    }

    for (auto i : rooms) {
        cout << i;
    }
    cout << endl;

}