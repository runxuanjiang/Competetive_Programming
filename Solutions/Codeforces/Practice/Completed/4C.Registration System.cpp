//Competition #:
//Problem #:
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
    ll n;
    cin >> n;
    unordered_map<string, int> um;
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        if (um.find(name) == um.end()) {
            um[name] = 1;
            cout << "OK" << endl;
        }
        else {
            cout << name << um[name] << endl;
            ++um[name];
        }
    }
}