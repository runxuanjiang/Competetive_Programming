//Competition #:
//Problem #: I
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

bool check(const string &s) {
    for (auto i : s) {
        if (!isdigit(i)) {
            return false;
        }
    }
    return true;
}

int main() {
    fast;
    string a, b;
    cin >> a >> b;

    if (check(a) && check(b)) {
        cout <<  stoi(a) - stoi(b) << endl;
    }
    else {
        cout << "NaN" << endl;
    }

}